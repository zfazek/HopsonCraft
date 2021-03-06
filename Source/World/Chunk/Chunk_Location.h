#ifndef VECTOR_H
#define VECTOR_H

#include <functional>
#include <cmath>

#include "../../Util/Hasher.h"

struct Chunk_Location
{
    Chunk_Location() = default;
    Chunk_Location (int x, int z);

    int x = 0;
    int z = 0;

    bool operator== (const Chunk_Location& other) const;

    bool operator!=  (const Chunk_Location& other) const;
};

namespace std
{
    template<>
    struct hash<Chunk_Location>
    {
        size_t operator() (Chunk_Location const& v ) const
        {
            return Hasher::hash(v.x, v.z);
        }
    };
}

#endif // VECTOR_H
