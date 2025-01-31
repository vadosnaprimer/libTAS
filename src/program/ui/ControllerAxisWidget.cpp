/*
    Copyright 2015-2023 Clément Gallet <clement.gallet@ens-lyon.org>

    This file is part of libTAS.

    libTAS is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libTAS is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libTAS.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <QtGui/QPainter>
#include <cstdint>
#include <iostream>

#include "ControllerAxisWidget.h"

ControllerAxisWidget::ControllerAxisWidget(QWidget *parent) : QWidget(parent)
{
    x_axis = y_axis = 0;

    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);
    // when(FL_WHEN_CHANGED);
}

QSize ControllerAxisWidget::sizeHint() const
{
    return QSize(200, 200);
}

QSize ControllerAxisWidget::minimumSizeHint() const
{
    return QSize(200, 200);
}

void ControllerAxisWidget::resizeEvent(QResizeEvent *)
{
    /* Force square aspect ratio */
    if (width() > height()) {
        size = height();
        x_offset = (width() - height()) / 2;
        y_offset = 0;
    } else {
        size = width();
        x_offset = 0;
        y_offset = (height() - width()) / 2;
    }
}

void ControllerAxisWidget::paintEvent(QPaintEvent * /* event */)
{
    QRect rect(x_offset+2, y_offset+2, size-4, size-4);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    painter.setBrush(QBrush(Qt::white));
    painter.setPen(QPen(Qt::black, 2));

    painter.drawChord(rect, 0, 360 * 16);

    float value_x = x_offset + ((float)x_axis - INT16_MIN) * size / UINT16_MAX;
    float value_y = y_offset + ((float)y_axis - INT16_MIN) * size / UINT16_MAX;

    painter.setBrush(QBrush(Qt::blue));
    painter.setPen(QPen(Qt::blue, 2));

    painter.drawLine(QLineF(width()/2.0, height()/2.0, value_x, value_y));

    QRectF rect_value(value_x-5, value_y-5, 10, 10);
    painter.drawChord(rect_value, 0, 360 * 16);
}

/* Clip values to short */
short ControllerAxisWidget::clampToShort(int val)
{
    return (val>INT16_MAX)?INT16_MAX:((val<INT16_MIN)?INT16_MIN:static_cast<short>(val));
}

void ControllerAxisWidget::slotSetXAxis(int x)
{
    x_axis = clampToShort(x);
    update();
}

void ControllerAxisWidget::slotSetYAxis(int y)
{
    y_axis = clampToShort(y);
    update();
}

void ControllerAxisWidget::slotSetAxes(short x, short y)
{
    x_axis = x;
    y_axis = y;
    update();
}

void ControllerAxisWidget::mouseMoveEvent(QMouseEvent *event)
{
    if (!(event->buttons() & Qt::LeftButton)) {
        event->ignore();
        return;
    }

    int x_axis_unclamped = ((event->x() - x_offset) * UINT16_MAX / size) + INT16_MIN;
    int y_axis_unclamped = ((event->y() - y_offset) * UINT16_MAX / size) + INT16_MIN;

    x_axis = clampToShort(x_axis_unclamped);
    y_axis = clampToShort(y_axis_unclamped);

    update();

    emit XAxisChanged(x_axis);
    emit YAxisChanged(y_axis);
}

void ControllerAxisWidget::mousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::MiddleButton) {
        slotSetAxes(0, 0);
        emit XAxisChanged(0);
        emit YAxisChanged(0);
    }
    return mouseMoveEvent(event);
}
