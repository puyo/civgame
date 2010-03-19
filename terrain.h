#ifndef _TERRAIN_H_
#define _TERRAIN_H_

#include "types.h"
#include <string>
#include <vector>
#include <allegro.h>
#include <boost/shared_ptr.hpp>


class TERRAIN {
    public:
        TERRAIN() {}
        TERRAIN(const std::string& cfgfile);
        inline BITMAP * image(uchar trans_id) { return myimages[trans_id].get(); }
        inline ushort id() { return myid; }
    protected:
        ushort myid;
        typedef boost::shared_ptr<BITMAP> BITMAP_PTR;
        std::vector<BITMAP_PTR> myimages;
};


#endif
