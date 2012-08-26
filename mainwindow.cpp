#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

#include <QPainter>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    drawModeActionGroup = new QActionGroup(this);
    drawModeActionGroup->addAction(ui->actionLine);
    drawModeActionGroup->addAction(ui->actionRectangle);
    drawModeActionGroup->addAction(ui->actionFreeDraw);

    ui->actionFreeDraw->setChecked(true);
    ui->canvas->setMode (Canvas::FreeDraw);

//    connect (ui->actionReplay, SIGNAL(toggled(bool)), ui->canvas, SLOT(setReplay(bool)));
//    ui->actionReplay->setChecked (false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_action_Save_triggered()
{
    ui->canvas->getImage ()->save ("canvas1.png");
}

void MainWindow::on_actionLine_triggered()
{
    ui->canvas->setMode(Canvas::DrawLine);
}

void MainWindow::on_actionRectangle_triggered()
{
    ui->canvas->setMode(Canvas::DrawRectangle);
}

void MainWindow::on_actionFreeDraw_triggered()
{
    ui->canvas->setMode(Canvas::FreeDraw);
}
