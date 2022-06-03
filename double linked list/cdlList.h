#ifndef CDLL_H

    #define CDLL_H

#endif
class cdlList
{
    node *first,*last;
public:
    cdlList();
    void append(int x);
    void show();
    bool insertBefore(int d, int x);
    node *searchNode(int x);
};
