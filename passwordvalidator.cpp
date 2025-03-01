#include "passwordvalidator.h"

PasswordValidator::PasswordValidator(QObject* parent) : QValidator(parent)
{

}

QValidator::State PasswordValidator::validate(QString &str, int &pos) const
{
    QRegularExpression rex_1 = QRegularExpression("[\A0-9a-zA-Z]");
    QRegularExpression rex_2 = QRegularExpression("[^\A0-9a-zA-Z]");
    if (str.isEmpty())
    {
        return Acceptable;
    }
    if (str.contains(rex_2))
    {
        return Invalid;
    }
    if (str.contains(rex_1))
    {
        return Acceptable;
    } else
    {
        return Invalid;
    }
}
