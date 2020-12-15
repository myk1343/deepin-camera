/*
* Copyright (C) 2020 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
* Maintainer: shicetu <shicetu@uniontech.com>
*             hujianbo <hujianbo@uniontech.com>
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CAPPLICATION_H
#define CAPPLICATION_H

#include "mainwindow.h"

#include <DApplication>
#include <DGuiApplicationHelper>

#include <QProcess>

#include "../qtsingleapplication/qtsingleapplication.h"

class CApplication;

#if defined(dApp)
#undef dApp
#endif
#define dApp (static_cast<CApplication *>(QCoreApplication::instance()))

DWIDGET_USE_NAMESPACE

/**
* @brief CApplication　对主窗口事件进行处理
* 主窗口获取与设置，退出时间处理，调用进程等
*/
class CApplication : public QtSingleApplication
{
    Q_OBJECT
public:
    CApplication(int &argc, char **argv);

    /**
    * @brief setMainWindow　设置主窗口
    * @param window 主窗口对象
    */
    void setMainWindow(CMainWindow *window);

    /**
    * @brief setprocess　设置进程列表
    * @param process 进程表
    */
    void setprocess(QList<QProcess *> &process);

    /**
    * @brief getprocess　获得进程列表
    */
    QList<QProcess *> getprocess();

    /**
    * @brief getMainWindow　获得主窗口
    */
    CMainWindow *getMainWindow();

signals:
    /**
    * @brief popupConfirmDialog　弹出确认对话框
    */
    void popupConfirmDialog();

protected:
    /**
    * @brief handleQuitAction　退出事件处理
    */
    void handleQuitAction() override;

private:
    CMainWindow       *m_mainwindow;
    QList<QProcess *> m_camprocesslist;
};
#endif // CAPPLICATION_H
