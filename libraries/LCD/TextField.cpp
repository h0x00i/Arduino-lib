/*
 * Copyright (C) 2012 Southern Storm Software, Pty Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a
 * copy of this software and associated documentation files (the "Software"),
 * to deal in the Software without restriction, including without limitation
 * the rights to use, copy, modify, merge, publish, distribute, sublicense,
 * and/or sell copies of the Software, and to permit persons to whom the
 * Software is furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#include "TextField.h"

/**
 * \class TextField TextField.h <TextField.h>
 * \brief Field that displays a read-only text value.
 *
 * This following example displays a text field with the label
 * "Form example" and a value() of "v1.0".
 *
 * \code
 * Form mainForm(lcd);
 * TextField welcomeField(mainForm, "Form example", "v1.0");
 * \endcode
 *
 * \image html FormText.png
 *
 * As well as static messages, TextField can be used to display read-only
 * information that is computed at runtime:
 *
 * \code
 * TextField timeField(mainForm, "Time since reset", "0");
 *
 * void loop() {
 *     timeField.setValue(millis() / 1000);
 *     mainForm.dispatch(lcd.getButton());
 * }
 * \endcode
 *
 * For writable fields, use BoolField, IntField, or TimeField.
 *
 * \sa Field
 */

/**
 * \brief Constructs a new text field with a specific \a label.
 *
 * The field is initially not associated with a Form.  The field can be
 * added to a form later using Form::addField().
 *
 * The initial value() will be the empty string.
 *
 * \sa Form::addField()
 */
TextField::TextField(const String &label)
    : Field(label)
{
}

/**
 * \brief Constructs a new text field with a specific \a label and \a value
 * attaches it to a \a form.
 *
 * \sa value()
 */
TextField::TextField(Form &form, const String &label, const String &value)
    : Field(form, label)
    , _value(value)
{
}

void TextField::enterField(bool reverse)
{
    Field::enterField(reverse);
    lcd()->setCursor(0, 1);
    lcd()->print(_value);
}

/**
 * \fn const String &TextField::value() const
 * \brief Returns the text value that is currently displayed by this field.
 *
 * \sa setValue()
 */

/**
 * \brief Sets the text \a value that is displayed by this field.
 *
 * \sa value()
 */
void TextField::setValue(const String &value)
{
    if (isCurrent()) {
        unsigned int prevLen = _value.length();
        unsigned int newLen = value.length();
        _value = value;
        lcd()->setCursor(0, 1);
        lcd()->print(value);
        while (newLen++ < prevLen)
            lcd()->write(' ');
    } else {
        _value = value;
    }
}
