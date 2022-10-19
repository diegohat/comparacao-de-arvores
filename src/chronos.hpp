#ifndef __CHRONOS_HPP__
#define __CHRONOS_HPP__

#include "randomizer.hpp"
#include "bst/fila.h"
#include "bst/tree.h"
#include "avl/avl.h"
#include "rbt/rb.h"
#include <chrono>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

void chronos(int);
void chronosAVL(int);
void chronosRBT(int);
void chronosVector(int);
void chronosMap(int);
void chronosUnorderedMap(int);

#endif