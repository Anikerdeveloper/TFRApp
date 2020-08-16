#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

    void on_LineTag_editingFinished();

    void on_AttributeLine_editingFinished();

    void on_ValueAttLine_editingFinished();

    void on_linefile_returnPressed();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
