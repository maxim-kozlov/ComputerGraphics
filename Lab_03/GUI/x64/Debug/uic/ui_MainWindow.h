/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabDraw;
    QHBoxLayout *horizontalLayout;
    QGraphicsView *graphicsView;
    QVBoxLayout *verticalLayoutToolsDraw;
    QTabWidget *tabWidgetDraw;
    QWidget *tabDrawLine;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayoutDrawLine;
    QVBoxLayout *verticalLayoutStartPoint;
    QLabel *labelA;
    QFormLayout *formLayoutStartPoint;
    QLabel *labelAx;
    QLabel *labelAy;
    QSpinBox *spinBoxStartX;
    QSpinBox *spinBoxStartY;
    QFrame *linePoints;
    QVBoxLayout *verticalLayoutEndPoint;
    QLabel *labelB;
    QFormLayout *formLayoutEndPoint;
    QLabel *labelBx;
    QLabel *labelBy;
    QSpinBox *spinBoxEndX;
    QSpinBox *spinBoxEndY;
    QPushButton *pushButtonDrawLine;
    QWidget *tabDrawSun;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayoutSunPoint;
    QLabel *labelSunCenter;
    QFormLayout *formLayoutSun;
    QLabel *labelSunCenterX;
    QLabel *labelSunCenterY;
    QSpinBox *spinBoxSunCenterX;
    QSpinBox *spinBoxSunCenterY;
    QFrame *line;
    QFormLayout *formLayoutSunParametr;
    QLabel *labelSunAngleStep;
    QLabel *labelSunRadius;
    QSpinBox *spinBoxSunRadius;
    QSpinBox *spinBoxAngleStep;
    QPushButton *pushButtonDrawSun;
    QVBoxLayout *verticalLayoutColor;
    QVBoxLayout *verticalLayoutColorLabel;
    QHBoxLayout *horizontalLayoutColorLine;
    QLabel *labelTextColorLine;
    QLabel *labelColorLine;
    QPushButton *pushButtonChangeColorLine;
    QHBoxLayout *horizontalLayoutColorBackGround;
    QLabel *labelTextColorBackGround;
    QLabel *labelColorBackGround;
    QPushButton *pushButtonChangeColorBackGround;
    QHBoxLayout *horizontalLayoutColorButton;
    QPushButton *pushButtonSwapColor;
    QPushButton *pushButtonClear;
    QComboBox *comboBoxPainters;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabTime;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayoutTabTime;
    QWidget *tabRungs;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayoutTabRungs;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1100, 700);
        MainWindow->setMinimumSize(QSize(1100, 700));
        MainWindow->setMaximumSize(QSize(1100, 700));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QFont font;
        font.setPointSize(10);
        tabWidget->setFont(font);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabDraw = new QWidget();
        tabDraw->setObjectName(QString::fromUtf8("tabDraw"));
        horizontalLayout = new QHBoxLayout(tabDraw);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        graphicsView = new QGraphicsView(tabDraw);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setMinimumSize(QSize(770, 570));
        graphicsView->setMaximumSize(QSize(770, 570));

        horizontalLayout->addWidget(graphicsView);

        verticalLayoutToolsDraw = new QVBoxLayout();
        verticalLayoutToolsDraw->setSpacing(6);
        verticalLayoutToolsDraw->setObjectName(QString::fromUtf8("verticalLayoutToolsDraw"));
        tabWidgetDraw = new QTabWidget(tabDraw);
        tabWidgetDraw->setObjectName(QString::fromUtf8("tabWidgetDraw"));
        tabWidgetDraw->setTabShape(QTabWidget::Triangular);
        tabWidgetDraw->setElideMode(Qt::ElideNone);
        tabDrawLine = new QWidget();
        tabDrawLine->setObjectName(QString::fromUtf8("tabDrawLine"));
        verticalLayout_2 = new QVBoxLayout(tabDrawLine);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayoutDrawLine = new QVBoxLayout();
        verticalLayoutDrawLine->setSpacing(6);
        verticalLayoutDrawLine->setObjectName(QString::fromUtf8("verticalLayoutDrawLine"));
        verticalLayoutStartPoint = new QVBoxLayout();
        verticalLayoutStartPoint->setSpacing(6);
        verticalLayoutStartPoint->setObjectName(QString::fromUtf8("verticalLayoutStartPoint"));
        labelA = new QLabel(tabDrawLine);
        labelA->setObjectName(QString::fromUtf8("labelA"));

        verticalLayoutStartPoint->addWidget(labelA);

        formLayoutStartPoint = new QFormLayout();
        formLayoutStartPoint->setSpacing(6);
        formLayoutStartPoint->setObjectName(QString::fromUtf8("formLayoutStartPoint"));
        labelAx = new QLabel(tabDrawLine);
        labelAx->setObjectName(QString::fromUtf8("labelAx"));

        formLayoutStartPoint->setWidget(0, QFormLayout::LabelRole, labelAx);

        labelAy = new QLabel(tabDrawLine);
        labelAy->setObjectName(QString::fromUtf8("labelAy"));

        formLayoutStartPoint->setWidget(1, QFormLayout::LabelRole, labelAy);

        spinBoxStartX = new QSpinBox(tabDrawLine);
        spinBoxStartX->setObjectName(QString::fromUtf8("spinBoxStartX"));
        spinBoxStartX->setMaximum(770);

        formLayoutStartPoint->setWidget(0, QFormLayout::FieldRole, spinBoxStartX);

        spinBoxStartY = new QSpinBox(tabDrawLine);
        spinBoxStartY->setObjectName(QString::fromUtf8("spinBoxStartY"));
        spinBoxStartY->setMaximum(570);

        formLayoutStartPoint->setWidget(1, QFormLayout::FieldRole, spinBoxStartY);


        verticalLayoutStartPoint->addLayout(formLayoutStartPoint);


        verticalLayoutDrawLine->addLayout(verticalLayoutStartPoint);

        linePoints = new QFrame(tabDrawLine);
        linePoints->setObjectName(QString::fromUtf8("linePoints"));
        linePoints->setFrameShape(QFrame::HLine);
        linePoints->setFrameShadow(QFrame::Sunken);

        verticalLayoutDrawLine->addWidget(linePoints);

        verticalLayoutEndPoint = new QVBoxLayout();
        verticalLayoutEndPoint->setSpacing(6);
        verticalLayoutEndPoint->setObjectName(QString::fromUtf8("verticalLayoutEndPoint"));
        labelB = new QLabel(tabDrawLine);
        labelB->setObjectName(QString::fromUtf8("labelB"));

        verticalLayoutEndPoint->addWidget(labelB);

        formLayoutEndPoint = new QFormLayout();
        formLayoutEndPoint->setSpacing(6);
        formLayoutEndPoint->setObjectName(QString::fromUtf8("formLayoutEndPoint"));
        labelBx = new QLabel(tabDrawLine);
        labelBx->setObjectName(QString::fromUtf8("labelBx"));

        formLayoutEndPoint->setWidget(0, QFormLayout::LabelRole, labelBx);

        labelBy = new QLabel(tabDrawLine);
        labelBy->setObjectName(QString::fromUtf8("labelBy"));

        formLayoutEndPoint->setWidget(1, QFormLayout::LabelRole, labelBy);

        spinBoxEndX = new QSpinBox(tabDrawLine);
        spinBoxEndX->setObjectName(QString::fromUtf8("spinBoxEndX"));
        spinBoxEndX->setMaximum(770);

        formLayoutEndPoint->setWidget(0, QFormLayout::FieldRole, spinBoxEndX);

        spinBoxEndY = new QSpinBox(tabDrawLine);
        spinBoxEndY->setObjectName(QString::fromUtf8("spinBoxEndY"));
        spinBoxEndY->setMaximum(570);

        formLayoutEndPoint->setWidget(1, QFormLayout::FieldRole, spinBoxEndY);


        verticalLayoutEndPoint->addLayout(formLayoutEndPoint);


        verticalLayoutDrawLine->addLayout(verticalLayoutEndPoint);


        verticalLayout_2->addLayout(verticalLayoutDrawLine);

        pushButtonDrawLine = new QPushButton(tabDrawLine);
        pushButtonDrawLine->setObjectName(QString::fromUtf8("pushButtonDrawLine"));

        verticalLayout_2->addWidget(pushButtonDrawLine);

        tabWidgetDraw->addTab(tabDrawLine, QString());
        tabDrawSun = new QWidget();
        tabDrawSun->setObjectName(QString::fromUtf8("tabDrawSun"));
        verticalLayout_3 = new QVBoxLayout(tabDrawSun);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayoutSunPoint = new QVBoxLayout();
        verticalLayoutSunPoint->setSpacing(6);
        verticalLayoutSunPoint->setObjectName(QString::fromUtf8("verticalLayoutSunPoint"));
        labelSunCenter = new QLabel(tabDrawSun);
        labelSunCenter->setObjectName(QString::fromUtf8("labelSunCenter"));

        verticalLayoutSunPoint->addWidget(labelSunCenter);

        formLayoutSun = new QFormLayout();
        formLayoutSun->setSpacing(6);
        formLayoutSun->setObjectName(QString::fromUtf8("formLayoutSun"));
        labelSunCenterX = new QLabel(tabDrawSun);
        labelSunCenterX->setObjectName(QString::fromUtf8("labelSunCenterX"));

        formLayoutSun->setWidget(0, QFormLayout::LabelRole, labelSunCenterX);

        labelSunCenterY = new QLabel(tabDrawSun);
        labelSunCenterY->setObjectName(QString::fromUtf8("labelSunCenterY"));

        formLayoutSun->setWidget(1, QFormLayout::LabelRole, labelSunCenterY);

        spinBoxSunCenterX = new QSpinBox(tabDrawSun);
        spinBoxSunCenterX->setObjectName(QString::fromUtf8("spinBoxSunCenterX"));
        spinBoxSunCenterX->setMaximum(770);
        spinBoxSunCenterX->setValue(385);

        formLayoutSun->setWidget(0, QFormLayout::FieldRole, spinBoxSunCenterX);

        spinBoxSunCenterY = new QSpinBox(tabDrawSun);
        spinBoxSunCenterY->setObjectName(QString::fromUtf8("spinBoxSunCenterY"));
        spinBoxSunCenterY->setMaximum(570);
        spinBoxSunCenterY->setValue(285);

        formLayoutSun->setWidget(1, QFormLayout::FieldRole, spinBoxSunCenterY);


        verticalLayoutSunPoint->addLayout(formLayoutSun);


        verticalLayout_3->addLayout(verticalLayoutSunPoint);

        line = new QFrame(tabDrawSun);
        line->setObjectName(QString::fromUtf8("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_3->addWidget(line);

        formLayoutSunParametr = new QFormLayout();
        formLayoutSunParametr->setSpacing(6);
        formLayoutSunParametr->setObjectName(QString::fromUtf8("formLayoutSunParametr"));
        labelSunAngleStep = new QLabel(tabDrawSun);
        labelSunAngleStep->setObjectName(QString::fromUtf8("labelSunAngleStep"));

        formLayoutSunParametr->setWidget(0, QFormLayout::LabelRole, labelSunAngleStep);

        labelSunRadius = new QLabel(tabDrawSun);
        labelSunRadius->setObjectName(QString::fromUtf8("labelSunRadius"));

        formLayoutSunParametr->setWidget(2, QFormLayout::LabelRole, labelSunRadius);

        spinBoxSunRadius = new QSpinBox(tabDrawSun);
        spinBoxSunRadius->setObjectName(QString::fromUtf8("spinBoxSunRadius"));
        spinBoxSunRadius->setMinimum(1);
        spinBoxSunRadius->setMaximum(1000);
        spinBoxSunRadius->setValue(200);

        formLayoutSunParametr->setWidget(2, QFormLayout::FieldRole, spinBoxSunRadius);

        spinBoxAngleStep = new QSpinBox(tabDrawSun);
        spinBoxAngleStep->setObjectName(QString::fromUtf8("spinBoxAngleStep"));
        spinBoxAngleStep->setMinimum(1);
        spinBoxAngleStep->setMaximum(360);
        spinBoxAngleStep->setValue(10);

        formLayoutSunParametr->setWidget(1, QFormLayout::FieldRole, spinBoxAngleStep);


        verticalLayout_3->addLayout(formLayoutSunParametr);

        pushButtonDrawSun = new QPushButton(tabDrawSun);
        pushButtonDrawSun->setObjectName(QString::fromUtf8("pushButtonDrawSun"));

        verticalLayout_3->addWidget(pushButtonDrawSun);

        tabWidgetDraw->addTab(tabDrawSun, QString());

        verticalLayoutToolsDraw->addWidget(tabWidgetDraw);

        verticalLayoutColor = new QVBoxLayout();
        verticalLayoutColor->setSpacing(6);
        verticalLayoutColor->setObjectName(QString::fromUtf8("verticalLayoutColor"));
        verticalLayoutColorLabel = new QVBoxLayout();
        verticalLayoutColorLabel->setSpacing(6);
        verticalLayoutColorLabel->setObjectName(QString::fromUtf8("verticalLayoutColorLabel"));
        horizontalLayoutColorLine = new QHBoxLayout();
        horizontalLayoutColorLine->setSpacing(6);
        horizontalLayoutColorLine->setObjectName(QString::fromUtf8("horizontalLayoutColorLine"));
        labelTextColorLine = new QLabel(tabDraw);
        labelTextColorLine->setObjectName(QString::fromUtf8("labelTextColorLine"));

        horizontalLayoutColorLine->addWidget(labelTextColorLine);

        labelColorLine = new QLabel(tabDraw);
        labelColorLine->setObjectName(QString::fromUtf8("labelColorLine"));
        labelColorLine->setEnabled(false);
        labelColorLine->setMinimumSize(QSize(70, 0));
        labelColorLine->setMaximumSize(QSize(70, 16777215));

        horizontalLayoutColorLine->addWidget(labelColorLine);

        pushButtonChangeColorLine = new QPushButton(tabDraw);
        pushButtonChangeColorLine->setObjectName(QString::fromUtf8("pushButtonChangeColorLine"));

        horizontalLayoutColorLine->addWidget(pushButtonChangeColorLine);


        verticalLayoutColorLabel->addLayout(horizontalLayoutColorLine);

        horizontalLayoutColorBackGround = new QHBoxLayout();
        horizontalLayoutColorBackGround->setSpacing(6);
        horizontalLayoutColorBackGround->setObjectName(QString::fromUtf8("horizontalLayoutColorBackGround"));
        labelTextColorBackGround = new QLabel(tabDraw);
        labelTextColorBackGround->setObjectName(QString::fromUtf8("labelTextColorBackGround"));

        horizontalLayoutColorBackGround->addWidget(labelTextColorBackGround);

        labelColorBackGround = new QLabel(tabDraw);
        labelColorBackGround->setObjectName(QString::fromUtf8("labelColorBackGround"));
        labelColorBackGround->setEnabled(false);
        labelColorBackGround->setMinimumSize(QSize(70, 0));
        labelColorBackGround->setMaximumSize(QSize(70, 16777215));

        horizontalLayoutColorBackGround->addWidget(labelColorBackGround);

        pushButtonChangeColorBackGround = new QPushButton(tabDraw);
        pushButtonChangeColorBackGround->setObjectName(QString::fromUtf8("pushButtonChangeColorBackGround"));

        horizontalLayoutColorBackGround->addWidget(pushButtonChangeColorBackGround);


        verticalLayoutColorLabel->addLayout(horizontalLayoutColorBackGround);


        verticalLayoutColor->addLayout(verticalLayoutColorLabel);

        horizontalLayoutColorButton = new QHBoxLayout();
        horizontalLayoutColorButton->setSpacing(6);
        horizontalLayoutColorButton->setObjectName(QString::fromUtf8("horizontalLayoutColorButton"));
        pushButtonSwapColor = new QPushButton(tabDraw);
        pushButtonSwapColor->setObjectName(QString::fromUtf8("pushButtonSwapColor"));

        horizontalLayoutColorButton->addWidget(pushButtonSwapColor);

        pushButtonClear = new QPushButton(tabDraw);
        pushButtonClear->setObjectName(QString::fromUtf8("pushButtonClear"));

        horizontalLayoutColorButton->addWidget(pushButtonClear);


        verticalLayoutColor->addLayout(horizontalLayoutColorButton);


        verticalLayoutToolsDraw->addLayout(verticalLayoutColor);

        comboBoxPainters = new QComboBox(tabDraw);
        comboBoxPainters->setObjectName(QString::fromUtf8("comboBoxPainters"));
        comboBoxPainters->setEditable(false);

        verticalLayoutToolsDraw->addWidget(comboBoxPainters);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayoutToolsDraw->addItem(verticalSpacer_2);


        horizontalLayout->addLayout(verticalLayoutToolsDraw);

        tabWidget->addTab(tabDraw, QString());
        tabTime = new QWidget();
        tabTime->setObjectName(QString::fromUtf8("tabTime"));
        horizontalLayout_3 = new QHBoxLayout(tabTime);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayoutTabTime = new QHBoxLayout();
        horizontalLayoutTabTime->setSpacing(6);
        horizontalLayoutTabTime->setObjectName(QString::fromUtf8("horizontalLayoutTabTime"));

        horizontalLayout_3->addLayout(horizontalLayoutTabTime);

        tabWidget->addTab(tabTime, QString());
        tabRungs = new QWidget();
        tabRungs->setObjectName(QString::fromUtf8("tabRungs"));
        verticalLayout_4 = new QVBoxLayout(tabRungs);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        horizontalLayoutTabRungs = new QHBoxLayout();
        horizontalLayoutTabRungs->setSpacing(6);
        horizontalLayoutTabRungs->setObjectName(QString::fromUtf8("horizontalLayoutTabRungs"));

        verticalLayout_4->addLayout(horizontalLayoutTabRungs);

        tabWidget->addTab(tabRungs, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1100, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidgetDraw->setCurrentIndex(1);
        comboBoxPainters->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelA->setText(QCoreApplication::translate("MainWindow", "Start Point", nullptr));
        labelAx->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        labelAy->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        labelB->setText(QCoreApplication::translate("MainWindow", "End Point", nullptr));
        labelBx->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        labelBy->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        pushButtonDrawLine->setText(QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        tabWidgetDraw->setTabText(tabWidgetDraw->indexOf(tabDrawLine), QCoreApplication::translate("MainWindow", "Draw Line", nullptr));
        labelSunCenter->setText(QCoreApplication::translate("MainWindow", "Sun Center Point", nullptr));
        labelSunCenterX->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        labelSunCenterY->setText(QCoreApplication::translate("MainWindow", "y", nullptr));
        labelSunAngleStep->setText(QCoreApplication::translate("MainWindow", "\316\224\316\270", nullptr));
        labelSunRadius->setText(QCoreApplication::translate("MainWindow", "R", nullptr));
        pushButtonDrawSun->setText(QCoreApplication::translate("MainWindow", "Draw Sun", nullptr));
        tabWidgetDraw->setTabText(tabWidgetDraw->indexOf(tabDrawSun), QCoreApplication::translate("MainWindow", "Draw Sun", nullptr));
        labelTextColorLine->setText(QCoreApplication::translate("MainWindow", "Line", nullptr));
        labelColorLine->setText(QString());
        pushButtonChangeColorLine->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        labelTextColorBackGround->setText(QCoreApplication::translate("MainWindow", "Background", nullptr));
        labelColorBackGround->setText(QString());
        pushButtonChangeColorBackGround->setText(QCoreApplication::translate("MainWindow", "Change", nullptr));
        pushButtonSwapColor->setText(QCoreApplication::translate("MainWindow", "Swap", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Clear", nullptr));
        comboBoxPainters->setCurrentText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tabDraw), QCoreApplication::translate("MainWindow", "Draw", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTime), QCoreApplication::translate("MainWindow", "Time", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRungs), QCoreApplication::translate("MainWindow", "Rungs", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
