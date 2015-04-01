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
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_GenerateFrontEndClass
{
public:

    void setupUi(QDialog *GenerateFrontEndClass)
    {
        if (GenerateFrontEndClass->objectName().isEmpty())
            GenerateFrontEndClass->setObjectName(QString::fromUtf8("GenerateFrontEndClass"));
        GenerateFrontEndClass->resize(600, 400);

        retranslateUi(GenerateFrontEndClass);

        QMetaObject::connectSlotsByName(GenerateFrontEndClass);
    } // setupUi

    void retranslateUi(QDialog *GenerateFrontEndClass)
    {
        GenerateFrontEndClass->setWindowTitle(QApplication::translate("GenerateFrontEndClass", "GenerateFrontEnd", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GenerateFrontEndClass: public Ui_GenerateFrontEndClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GENERATEFRONTEND_H
