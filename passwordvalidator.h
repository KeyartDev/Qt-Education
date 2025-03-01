#ifndef PASSWORDVALIDATOR_H
#define PASSWORDVALIDATOR_H

#include "QValidator"
#include "QRegularExpression"

class PasswordValidator : public QValidator
{
public:
    PasswordValidator(QObject*);



    // QValidator interface
public:
    State validate(QString &, int &) const;
};

#endif // PASSWORDVALIDATOR_H
