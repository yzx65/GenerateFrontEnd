#include "generatefrontend.h"
#include "daemondlg.h"
#include "generatedlg.h"

GenerateFrontEnd::GenerateFrontEnd(QWidget *parent, Qt::WFlags flags)
	: QDialog(parent, flags)
{
	ui.setupUi(this);

	this->setWindowFlags(Qt::Dialog | Qt::WindowTitleHint);

	InitWidgetAppearance();
}

GenerateFrontEnd::~GenerateFrontEnd()
{

}

void GenerateFrontEnd::InitWidgetAppearance()
{
	QVBoxLayout* layout = new QVBoxLayout(ui.frmNavigator);
	ui.frmNavigator->setStyleSheet("QFrame{background-color:rgb(247, 249, 255);border:0px solid #cccccc;border-right-width:1px;}");
	layout->setContentsMargins(0, 0, 0, 0);
	layout->setSpacing(0);
	AddPage(QString::fromLocal8Bit("生成中转"), new DaemonDlg);
	AddPage(QString::fromLocal8Bit("生成前端"), new GenerateDlg);
	layout->addSpacerItem(new QSpacerItem(20, 10, QSizePolicy::Fixed, QSizePolicy::Expanding));

	m_pageMap[QString::fromLocal8Bit("生成中转")].btn->setChecked(true);
}

void GenerateFrontEnd::AddPage(QString pageName, QWidget* page)
{
	QRadioButton* btn = new QRadioButton(this);
	btn->setText(pageName);
	btn->setObjectName(pageName);
	btn->setStyleSheet(
		"QRadioButton::indicator{width:0px;height:0px;}"
		"QRadioButton{background-color:rgb(247, 249, 255);border:0px solid #cccccc;border-bottom-width:1px;min-width:120px;min-height:35px;font-family:'Microsoft Yahei';font-size:12px;color:black;padding-left:20px;}"
		"QRadioButton:hover{background-color:rgb(209, 216, 240);color:black;}"
		"QRadioButton:checked{background-color:rgb(133, 153, 216);color:white;}");
	connect(btn, SIGNAL(clicked()), this, SLOT(CurrentPageChanged()));
	ui.frmNavigator->layout()->addWidget(btn);
	int index = ui.stack->addWidget(page);

	PageInfo info = {index, btn};
	m_pageMap[pageName] = info;
}

void GenerateFrontEnd::CurrentPageChanged()
{
	QRadioButton* btn = qobject_cast<QRadioButton*>(sender());

	int index = m_pageMap[btn->text()].stackIndex;
	ui.stack->setCurrentIndex(index);
}
