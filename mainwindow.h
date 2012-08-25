#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
class QActionGroup;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void on_action_Save_triggered();

    void on_actionLine_triggered();

    void on_actionRectangle_triggered();

    void on_actionFreeDraw_triggered ();

private:
    Ui::MainWindow *ui;
    QActionGroup *drawModeActionGroup;
};

#endif // MAINWINDOW_H
