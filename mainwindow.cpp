#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QListWidgetItem>
#include <QListWidget>
#include <QLabel>
#include <QTextBlock>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("Parser"));

    Mode = createMode();
    NodeListViewer = createNodeListViewer();
    Previewer = createPreviewer();

    /* top window */
    QVBoxLayout *topLayout = new QVBoxLayout;
    topLayout->addWidget(Mode);

    /* buttom window*/
    QHBoxLayout *buttomLayout = new QHBoxLayout;

    /* left window in buttom window*/
    QVBoxLayout *left_layout = new QVBoxLayout;
    QPushButton *getNodeList = new QPushButton("Refresh");
    left_layout->addWidget(NodeListViewer);
    left_layout->addWidget(getNodeList);
    buttomLayout->addLayout(left_layout);

    /* right window in buttom window */
    buttomLayout->addWidget(Previewer);

    QWidget *window = new QWidget();
    topLayout->addLayout(buttomLayout);
    window->setLayout(topLayout);


    setCentralWidget(window);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QGroupBox *MainWindow::createMode(){
    QGroupBox *groupBox = new QGroupBox("Mode");
    QVBoxLayout *toplayout = new QVBoxLayout;

    QPushButton *measurer = new QPushButton("Measurer");
    QPushButton *analyzer = new QPushButton("Analyzer");
    QPushButton *scheduler = new QPushButton("Scheduler");
    QPushButton *tracer = new QPushButton("Tracer");

    measurer->setCheckable(true);
    analyzer->setCheckable(true);
    scheduler->setCheckable(true);
    tracer->setCheckable(true);

    QHBoxLayout *modeLayout = new QHBoxLayout;
    modeLayout->addWidget(measurer);
    modeLayout->addWidget(analyzer);
    modeLayout->addWidget(scheduler);
    modeLayout->addWidget(tracer);

    QButtonGroup* ExclusiveButtons = new QButtonGroup;
    ExclusiveButtons->addButton(measurer);
    ExclusiveButtons->addButton(analyzer);
    ExclusiveButtons->addButton(scheduler);
    ExclusiveButtons->addButton(tracer);
    ExclusiveButtons->setExclusive(true);

    toplayout->addLayout(modeLayout);
    groupBox->setLayout(toplayout);


    return groupBox;
}

QGroupBox *MainWindow::createNodeListViewer(){
    QGroupBox *groupBox = new QGroupBox("Node List");
    QVBoxLayout *toplayout = new QVBoxLayout;

    widget = new QListWidget;
    QStringList strList;
    strList << "/talker" << "/listener" << "/rosout" << "/ssd"
            << "graphic card" << "sound card" << "memory" << "motherboard";

    widget->addItems(strList);

    QListWidgetItem* item = 0;
    for(int i = 0; i < widget->count(); ++i){
        item = widget->item(i);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable);
        item->setCheckState(Qt::Unchecked);
    }

    QObject::connect(widget, SIGNAL(itemChanged(QListWidgetItem*)),
                     this, SLOT(highlightChecked(QListWidgetItem*)));
    toplayout->addWidget(widget);
    groupBox->setLayout(toplayout);

    return groupBox;
}

QGroupBox *MainWindow::createPreviewer(){
    QGroupBox *groupBox = new QGroupBox("Preview");
    QVBoxLayout *toplayout = new QVBoxLayout;

    QPushButton *button1 = new QPushButton("temp1");
    QPushButton *button = new QPushButton("temp2");
    toplayout->addWidget(button1);
    toplayout->addWidget(button);

    groupBox->setLayout(toplayout);

return groupBox;
}

void MainWindow::highlightChecked(QListWidgetItem *item){
    if(item->checkState() == Qt::Checked)
        item->setBackgroundColor(QColor("#ffffb2"));
    else
        item->setBackgroundColor(QColor("#ffffff"));
}
