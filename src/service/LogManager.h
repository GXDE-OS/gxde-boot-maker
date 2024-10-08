/*
 * Copyright (C) 2017 ~ 2018 Wuhan Deepin Technology Co., Ltd.
 *
 * Author:     Iceyer <me@iceyer.net>
 *
 * Maintainer: Iceyer <me@iceyer.net>
 *
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

#pragma once

#include <QtCore>

#include "dobject.h"
#include <Logger.h>
#include <ConsoleAppender.h>
#include <RollingFileAppender.h>

class DBMLogManager
{
public:
    static void setSystemLog(bool sys);
    static void registerConsoleAppender();
    static void registerFileAppender();
    static QString getlogFilePath();
    static void setLogFormat(const QString& format);

signals:

public slots:

private:
    bool systemLog = false;
    QString m_format;
    QString m_logPath;
    Dtk::Core::ConsoleAppender* m_consoleAppender;
    Dtk::Core::RollingFileAppender* m_rollingFileAppender;

    void initConsoleAppender();
    void initRollingFileAppender();
    QString joinPath(const QString& path, const QString& fileName);

    inline static DBMLogManager* instance(){
        static DBMLogManager instance;
        return &instance;
    }
    explicit DBMLogManager();
    ~DBMLogManager();
    DBMLogManager(const DBMLogManager &);
    DBMLogManager & operator = (const DBMLogManager &);
};

