#ifndef GENERATEFRONTEND_H
#define GENERATEFRONTEND_H

#include <QtGui/QDialog>
#include "ui_generatefrontend.h"

class GenerateFrontEnd : public QDialog
{
	Q_OBJECT

public:
	GenerateFrontEnd(QWidget *parent = 0, Qt::WFlags flags = 0);
	~GenerateFrontEnd();

private:
	Ui::GenerateFrontEndClass ui;
};

#endif // GENERATEFRONTEND_H
