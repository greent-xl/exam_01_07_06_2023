#ifndef SINGDB_H
#define SINGDB_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QDebug>


class SingDB;

class SingDestDB
{
private:
    SingDB * p_instan;
public:

    ~SingDestDB();

    void initial(SingDB * p);
};

class SingDB
{
private:
    static SingDB * p_instan;
    static SingDestDB dest;
    QSqlDatabase db;
    QStringList res;
protected:
    SingDB();
    SingDB(const SingDB&) = delete;
    SingDB& operator = (SingDB&) = delete;
    ~SingDB();
    friend class SingDestDB;

public:
    static SingDB * getInstance();

    QStringList getValue(QString);
};



#endif // SINGDB_H
