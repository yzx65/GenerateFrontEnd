/********************************************************************************
** Form generated from reading UI file 'generatefrontend.ui'
**
** Created by: Qt User Interface Compiler version 4.8.6
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GENERATEFRONTEND_H
#define UI_GENERATEFRONTEND_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QFrame>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QStackedWidget>

QT_BEGIN_NAMESPACE

class Ui_GenerateFrontEndClass
{
public:
    QHBoxLayout *horizontalLayout;
    QFrame *frmNavigator;
    QStackedWidget *stack;

    void setupUi(QDialog *GenerateFrontEndClass)
    {
        if (GenerateFrontEndClass->objectName().isEmpty())
            GenerateFrontEndClass->setObjectName(QString::fromUtf8("GenerateFrontEndClass"));
        GenerateFrontEndClass->resize(600, 458);
        horizontalLayout = new QHBoxLayout(GenerateFrontEndClass);
        horizontalLayout->setSpacing(0);
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        frmNavigator = new QFrame(GenerateFrontEndClass);
        frmNavigator->setObjectName(QString::fromUtf8("frmNavigator"));
        frmNavigator->setMinimumSize(QSize(150, 0));
        frmNavigator->setFrameShape(QFrame::StyledPanel);
        frmNavigator->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frmNavigator);

        stack = new QStackedWidget(GenerateFrontEndClass);
        stack->setObjectName(QString::fromUtf8("stack"));

        horizontalLayout->addWidget(stack);


        retranslateUi(GenerateFrontEndClass);

        QMetaObject::connectSlotsByName(GenerateFrontEndClass);
    } // setupUi

    void retranslateUi(QDialog *GenerateFrontEndClass)
    {
        GenerateFrontEndClass->setWindowTitle(QApplication::translate("GenerateFrontEndClass", "\350\277\234\347\250\213\346\216\247\345\210\266\345\271\263\345\217\260-\347\224\237\346\210\220", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GenerateFrontEndClass: public Ui_GenerateFrontEndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEFRONTEND_H
