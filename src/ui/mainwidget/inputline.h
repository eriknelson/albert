// albert - a simple application launcher for linux
// Copyright (C) 2014 Manuel Schneider
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

#ifndef INPUTLINE_H
#define INPUTLINE_H

#include <QLineEdit>

#include "settingsbutton.h"
#include "history.h"

class InputLine : public QLineEdit
{
	Q_OBJECT
	friend class SettingsWidget;

public:
	explicit InputLine(QWidget *parent = 0);
	~InputLine();

	void saveSettings(QSettings &s) const;
	void loadSettings(QSettings &s);
	void serilizeData(QDataStream &out) const;
	void deserilizeData(QDataStream &in);

protected:
	void resizeEvent(QResizeEvent*) override;
	void keyPressEvent(QKeyEvent*) override;

private:
	SettingsButton *_settingsButton;
	History		   _history;

signals:
	void settingsDialogRequested();

public slots:
	void reset();
};

#endif // INPUTLINE_H
