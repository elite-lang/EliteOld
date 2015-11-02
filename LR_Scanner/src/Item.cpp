/*
 * <one line to give the program's name and a brief idea of what it does.>
 * Copyright (C) 2014  <copyright holder> <email>
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * 
 */

#include "Item.h"

Item::Item()
{
    bnf = NULL;
    itempoint = 0;
}

Item::Item(const Item& other)
{
    bnf = other.bnf;
    itempoint = other.itempoint;
    if (other.getLookahead().size() != 0) {
        lookahead = other.lookahead;
    }
}

Item::~Item()
{

}

Item& Item::operator=(const Item& other)
{
    bnf = other.bnf;
    itempoint = other.itempoint;
    lookahead = other.lookahead;
}

bool Item::operator==(const Item& other) const
{
//    if (bnf == other.bnf && itempoint == other.itempoint && lookahead == other.lookahead) return true;
    // 我们去掉了向前看符号的比较，为的是尽可能的将同心项合并
    if (bnf == other.bnf && itempoint == other.itempoint) return true;
    return false;
}

bool Item::operator<(const Item& other) const
{
    if (bnf < other.bnf) return true;
    if (bnf == other.bnf)
        if (itempoint < other.itempoint) return true;
    return false;
}

Item::Item(BNF* _bnf,int _itempoint)
{
    setItem(_bnf,_itempoint);
}

void Item::setItem(BNF* _bnf,int _itempoint)
{
    bnf = _bnf;
    itempoint = _itempoint;
}

