/********************************************************************************
** Form generated from reading UI file 'daemondlg.ui'
**
** Created: Thu Apr 2 10:24:29 2015
**      by: Qt User Interface Compiler version 4.8.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DAEMONDLG_H
#define UI_DAEMONDLG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QCheckBox>
#include <QtGui/QDialog>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DaemonDlg
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer_3;
    QLineEdit *edtPort1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer_4;
    QLineEdit *edtPort2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QSpacerItem *horizontalSpacer_5;
    QLineEdit *edtPort3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label;
    QSpacerItem *horizontalSpacer_6;
    QLineEdit *edtPassword;
    QHBoxLayout *horizontalLayout_6;
    QCheckBox *chkEnableLog;
    QSpacerItem *horizontalSpacer_8;
    QCheckBox *chkShowLog;
    QSpacerItem *horizontalSpacer_7;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnOk;

    void setupUi(QDialog *DaemonDlg)
    {
        if (DaemonDlg->objectName().isEmpty())
            DaemonDlg->setObjectName(QString::fromUtf8("DaemonDlg"));
        DaemonDlg->resize(346, 439);
        DaemonDlg->setStyleSheet(QString::fromUtf8("QWidget\n"
"{\n"
"	font-family:\"MicroSoft Yahei\";\n"
"}\n"
"\n"
"QWidget#DaemonDlg\n"
"{\n"
"	background-color:white;\n"
"}"));
        verticalLayout = new QVBoxLayout(DaemonDlg);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(DaemonDlg);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setMinimumSize(QSize(0, 200));
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        verticalLayout_2 = new QVBoxLayout(tab_2);
        verticalLayout_2->setSpacing(10);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(tab_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(50, 25));
        label_2->setMaximumSize(QSize(50, 16777215));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_2);

        horizontalSpacer_3 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        edtPort1 = new QLineEdit(tab_2);
        edtPort1->setObjectName(QString::fromUtf8("edtPort1"));
        edtPort1->setMinimumSize(QSize(0, 25));

        horizontalLayout_4->addWidget(edtPort1);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(tab_2);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(50, 25));
        label_3->setMaximumSize(QSize(50, 16777215));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        horizontalSpacer_4 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        edtPort2 = new QLineEdit(tab_2);
        edtPort2->setObjectName(QString::fromUtf8("edtPort2"));
        edtPort2->setMinimumSize(QSize(0, 25));

        horizontalLayout_3->addWidget(edtPort2);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(tab_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setMinimumSize(QSize(50, 25));
        label_4->setMaximumSize(QSize(50, 16777215));
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label_4);

        horizontalSpacer_5 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_5);

        edtPort3 = new QLineEdit(tab_2);
        edtPort3->setObjectName(QString::fromUtf8("edtPort3"));
        edtPort3->setMinimumSize(QSize(0, 25));

        horizontalLayout_2->addWidget(edtPort3);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label = new QLabel(tab_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(50, 25));
        label->setMaximumSize(QSize(50, 16777215));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label);

        horizontalSpacer_6 = new QSpacerItem(10, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_6);

        edtPassword = new QLineEdit(tab_2);
        edtPassword->setObjectName(QString::fromUtf8("edtPassword"));
        edtPassword->setEchoMode(QLineEdit::Password);

        horizontalLayout_5->addWidget(edtPassword);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        chkEnableLog = new QCheckBox(tab_2);
        chkEnableLog->setObjectName(QString::fromUtf8("chkEnableLog"));
        chkEnableLog->setChecked(true);

        horizontalLayout_6->addWidget(chkEnableLog);

        horizontalSpacer_8 = new QSpacerItem(20, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_8);

        chkShowLog = new QCheckBox(tab_2);
        chkShowLog->setObjectName(QString::fromUtf8("chkShowLog"));
        chkShowLog->setChecked(true);

        horizontalLayout_6->addWidget(chkShowLog);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        verticalLayout_2->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnOk = new QPushButton(DaemonDlg);
        btnOk->setObjectName(QString::fromUtf8("btnOk"));
        btnOk->setMinimumSize(QSize(0, 25));

        horizontalLayout->addWidget(btnOk);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(DaemonDlg);

        QMetaObject::connectSlotsByName(DaemonDlg);
    } // setupUi

    void retranslateUi(QDialog *DaemonDlg)
    {
        DaemonDlg->setWindowTitle(QApplication::translate("DaemonDlg", "\347\224\237\346\210\220\344\270\255\350\275\254\346\234\215\345\212\241\345\231\250", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("DaemonDlg", "\351\200\232\344\277\241\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        edtPort1->setText(QApplication::translate("DaemonDlg", "8080", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("DaemonDlg", "\346\216\247\345\210\266\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        edtPort2->setText(QApplication::translate("DaemonDlg", "8088", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("DaemonDlg", "\346\225\260\346\215\256\347\253\257\345\217\243", 0, QApplication::UnicodeUTF8));
        edtPort3->setText(QApplication::translate("DaemonDlg", "8089", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DaemonDlg", "\351\252\214\350\257\201\347\240\201", 0, QApplication::UnicodeUTF8));
        chkEnableLog->setText(QApplication::translate("DaemonDlg", "\345\220\257\347\224\250\346\227\245\345\277\227\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
        chkShowLog->setText(QApplication::translate("DaemonDlg", "\346\230\276\347\244\272\346\227\245\345\277\227\347\252\227\345\217\243", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DaemonDlg", "\344\270\255\350\275\254\346\234\215\345\212\241\345\231\250\351\205\215\347\275\256", 0, QApplication::UnicodeUTF8));
        btnOk->setText(QApplication::translate("DaemonDlg", "\347\224\237\346\210\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DaemonDlg: public Ui_DaemonDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DAEMONDLG_H
