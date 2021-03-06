#include "UnlockDatabaseDialog.h"
#include "UnlockDatabaseWidget.h"

#include "autotype/AutoType.h"
#include <core/Database.h>


UnlockDatabaseDialog::UnlockDatabaseDialog(QWidget *parent)
    : QDialog(parent)
    , m_view(new UnlockDatabaseWidget(this))
{
    connect(m_view, SIGNAL(editFinished(bool)), this, SLOT(complete(bool)));
}

void UnlockDatabaseDialog::setDBFilename(const QString &filename)
{
    m_view->load(filename);
}

void UnlockDatabaseDialog::clearForms()
{
    m_view->clearForms();
}

Database *UnlockDatabaseDialog::database()
{
    return m_view->database();
}

void UnlockDatabaseDialog::complete(bool r)
{
    if (r) {
        accept();
        Q_EMIT unlockDone(true);
    } else {
        reject();
    }
}
