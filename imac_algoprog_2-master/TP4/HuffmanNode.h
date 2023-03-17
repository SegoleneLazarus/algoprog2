#ifndef HUFFMANNNODE_H
#define HUFFMANNNODE_H

#include <QString>

#include "binarytree.h"
#include "array.h"

struct HuffmanNode
{
    HuffmanNode* left;
    HuffmanNode* right;

    int frequences;
    unsigned char character;
    std::string code;

    HuffmanNode(unsigned char c='\0', int frequences=0) : Node(frequences)
    {
        this->frequences = frequences;
        this->character = c;
        this->code = std::string();
        this->left = this->right = NULL;
    }

    HuffmanNode(const HuffmanNode& node): Node(node)
    {
        this->frequences = node.frequences;
        this->character = node.character;
        this->code = std::string(node.code);
        this->left = this->right = NULL;
    }

    virtual bool isLeaf() const {return !this->left && !this->right;}

    void insertNode(HuffmanNode*);
    void processCodes(std::string baseCode);
    void fillCharactersArray(HuffmanNode** nodes_for_chars);


};


class HuffmanHeap : public TemplateArray<HuffmanNode>
{
public:
    virtual ~HuffmanHeap() {}

    HuffmanHeap(uint size=100) : TemplateArray<HuffmanNode>()
    {
        if (size>0)
        {
            _data.resize(size);
            for (uint i=0; i<size; ++i)
                _data[i] = -1;
        }
    }

    QString toString() const
    {
        QStringList list;
        for (const HuffmanNode& value : _data)
        {
            list.append(value.toString());
        }
        return QString("[%1]").arg(list.join(", "));
    }


    virtual size_t effectiveSize() const
    {
        return _data.size();
    }

    HuffmanNode& get(uint index) {
        return _data[index];
    }

    void insertHeapNode(int heapSize, unsigned char c, int frequences);
};

#endif // HUFFMANNNODE_H
