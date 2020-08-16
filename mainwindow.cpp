#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "TFR.h"
#include <iostream>

TFR fr;

struct TFRLAV {
    QString Tag;
    QString Attribute;
    QString Value;
};

TFRLAV tv;

std::string TFRFILES = "";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    fr.TFRFile("F:/IDE/Projects/Lesson/datafile.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_lineEdit_editingFinished()
{
    QString lol = ui->lineEdit->text();
   if (fr.TagCount(lol.toStdString()) != 0){
       ui->OutLabel->setText(QString::fromStdString(fr.ReadFromTag(lol.toStdString())));
   } else ui->OutLabel->setText("Такого тэга нет!");
}

void MainWindow::on_lineEdit_2_editingFinished()
{
    QString lol = ui->lineEdit_2->text();
   if (fr.TagCount(lol.toStdString()) != 0){
       ui->OutLabel->setText(QString::fromStdString(fr.GetMultiLine(lol.toStdString())));
   } else ui->OutLabel->setText("Такого тэга нет!");
}

void MainWindow::on_LineTag_editingFinished()
{
   tv.Tag = ui->LineTag->text();
   if (fr.TagCount(tv.Tag.toStdString()) == 0){
       ui->OutLabel->setText("Такого тэга нет!");
   } else ui->OutLabel->setText("Введите остальные данные");
}

void MainWindow::on_AttributeLine_editingFinished()
{
   tv.Attribute = ui->AttributeLine->text();
}

void MainWindow::on_ValueAttLine_editingFinished()
{


   tv.Value = ui->ValueAttLine->text();
   ui->OutLabel->setText(QString::fromStdString(fr.GetLineOfAttribute(tv.Tag.toStdString(), tv.Attribute.toStdString(), tv.Value.toStdString())));
}

void MainWindow::on_linefile_returnPressed()
{
    fr.TFRFile(ui->linefile->text().toStdString());
}
