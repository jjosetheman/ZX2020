/* Copyright (C) 2020  Doctor Volt

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileSystemWatcher>
#include <QSerialPort>
#include <QSettings>
#include <QDir>
#include <QStringList>
#include <loader.h>
#include <serialdisk.h>

#define PROGNAME "CP/M Loader"
#define NEWFILENAME "untitled"
#define FNAME_KEY "filename"

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
    void on_pButtonLoad_clicked();
    void on_actionLoad_triggered();
    void on_serialError(QSerialPort::SerialPortError);
    void on_sysfileChanged(const QString&);
    void on_loaderFinished();
    void on_timer();
    void on_actionSet_Kernel_File_triggered();
    void on_actionAbout_triggered();
    void on_pButtonReload_clicked();

private:
    Ui::MainWindow *ui;
    QString sysFileName;
    QString cpmPath;
    const QString homepath = QDir::homePath() + "/";

    QSerialPort *p_serial = new QSerialPort(this);
    QFileSystemWatcher *p_fileSystemWatcher = new QFileSystemWatcher(this);
    QSettings *p_settings = new QSettings("Doctor Volt", PROGNAME);
    Loader *p_loader = new Loader(p_serial, this);
    Serialdisk *p_serdisk = new Serialdisk(this);
    void setBinFile(const QString);

};
#endif // MAINWINDOW_H