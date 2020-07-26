#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <fstream>
#include <QDir>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    updateDotFile();
    updateImage();
    renderImage();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::updateDotFile()
{
    std::ofstream myFile;
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    myFile.open
    (
        "file.dot"
    );

    std::string textToFile;
    if (ui->radioButtonTrad->isChecked())
        textToFile = avlTree.gitDotFileMode1();
    else
        textToFile = avlTree.gitDotFileMode2();

    myFile << textToFile;
    myFile.close();
}

void MainWindow::updateImage()
{
    std::string message =
                "dot -Tpng file.dot > file.png";
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    system(message.c_str());
}

void MainWindow::renderImage()
{
    QDir::setCurrent(QCoreApplication::applicationFilePath());
    QPixmap image("file.png");
    ui->labelOfImage->setPixmap(image);
    ui->labelOfImage->show();
}

void MainWindow::on_pushButtonOfInsert_clicked()
{
    int toInsert = ui->lineEditOfInsert->text().toInt();

    AVLNode* inserted = avlTree.insertInterface(toInsert);

    updateDotFile();
    updateImage();
    renderImage();

    QMessageBox msgBox;
    if (inserted != nullptr)
        msgBox.setText("The node was inserted");
    else
        msgBox.setText("Already exists a node with this data");
    msgBox.exec();
}

void MainWindow::on_pushButtonOfSearch_clicked()
{
    int toSearch = ui->lineEditOfSearch->text().toInt();
    bool ret = avlTree.search(toSearch);

    QMessageBox msgBox;

    if (ret)
        msgBox.setText("There is a node with this data");
    else
        msgBox.setText("There is NOT a node with this data");

    msgBox.exec();
}

void MainWindow::on_pushButtonOfRemove_clicked()
{
    int toRemove = ui->lineEditOfRemove->text().toInt();
    AVLNode *node = avlTree.removeInterface(toRemove);

    updateDotFile();
    updateImage();
    renderImage();

    if (node != nullptr)
        delete node;
}

void MainWindow::on_pushButtonPreOrdem_clicked()
{
    //Eu, esq, direita

    std::string ret = avlTree.preOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmOrdem_clicked()
{
    //esq, eu, dir

    std::string ret = avlTree.inOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonPosOrdem_clicked()
{
    //esq, dir, eu

    std::string ret = avlTree.posOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_pushButtonEmNivel_clicked()
{
    //eu, filhos, netos, bisnetos

    std::string ret = avlTree.InLevelOrder();
    QMessageBox msgBox;
    msgBox.setText(ret.c_str());
    msgBox.exec();
}

void MainWindow::on_radioButtonTrad_toggled(bool checked)
{
    updateDotFile();
    updateImage();
    renderImage();
}
