#ifndef TREEMODEL_H
#define TREEMODEL_H


#include <QAbstractItemModel>
#include <QModelIndex>
#include <QVariant>

#include "../View/primitivedefinition.h"

class GlObject;

//! [0]
class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    TreeModel(QObject *parent = 0);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role) const Q_DECL_OVERRIDE;
    QVariant headerData(int, Qt::Orientation orientation,
                        int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    QModelIndex index(int row, int column,
                      const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    QModelIndex parent(const QModelIndex &index) const Q_DECL_OVERRIDE;

    int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
    int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;



    Qt::ItemFlags flags(const QModelIndex &index) const Q_DECL_OVERRIDE;
    bool setData(const QModelIndex &index, const QVariant &value,
                 int role = Qt::EditRole) Q_DECL_OVERRIDE;
    bool setHeaderData(int section, Qt::Orientation orientation,
                       const QVariant &value, int role = Qt::EditRole) Q_DECL_OVERRIDE;

//    bool insertColumns(int position, int columns,
//                       const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
//    bool removeColumns(int position, int columns,
//                       const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
//    bool insertRows(int position, int rows,
//                    const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;
//    bool removeRows(int position, int rows,
//                    const QModelIndex &parent = QModelIndex()) Q_DECL_OVERRIDE;

    void addObject(PrimitiveDefinition::Types t,
                   QModelIndex &parentIndex);
    void addToRoot(GlObject *item);
    QModelIndex addGroupToRoot();

    bool moveItems(const QModelIndexList& toMove, const QModelIndex& dest);

    bool removeRow(int row, const QModelIndex &parent);
    bool removeRow(const QModelIndex &toRemove);

    GlObject* copyObjectAt(const QModelIndex &index);
    bool isItemPrimitive(const QModelIndex &index) const;

private:
    //void setupModelData(const QStringList &lines, GlObject *parent);
    GlObject *getItem(const QModelIndex &index) const;

    GlObject *rootItem;
};
#endif // TREEMODEL_H
