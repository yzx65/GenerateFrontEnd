#ifndef GENERATEFRONTEND_H
#define GENERATEFRONTEND_H

#include <QtGui/QDialog>
#include "ui_generatefrontend.h"

class QRadioButton;

class GenerateFrontEnd : public QDialog
{
	Q_OBJECT

public:
	GenerateFrontEnd(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GenerateFrontEnd();

private:
	void InitWidgetAppearance();
	void AddPage(QString pageName, QWidget* page);

private slots:
	void CurrentPageChanged();

private:
	Ui::GenerateFrontEndClass ui;

	struct PageInfo
	{
		int stackIndex;
		QRadioButton* btn;
	};

	std::map<QString, PageInfo> m_pageMap;
};

#endif // GENERATEFRONTEND_H
