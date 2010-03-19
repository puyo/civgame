#include "terrain.h"
#include "map.h"
#include <cstdio>
#include <unistd.h>


static void bitmap_deleter(BITMAP * p) { 
    destroy_bitmap(p);
} 



TERRAIN::TERRAIN(const std::string& basefname): myimages(18) {
    std::string terraindir = "terrain/grasslnd/";
    std::string cfgfname(terraindir + basefname + ".cfg");
    if (!exists(cfgfname.c_str())) {
        fprintf(stderr, "Could not find terrain config file for terrain \"%s\".\n", basefname.c_str());
        exit(1);
    }
    std::string imagefname(terraindir + basefname + ".pcx");
    if (!exists(imagefname.c_str())) {
        fprintf(stderr, "Could not find image files for terrain \"%s\".\n", basefname.c_str());
        exit(1);
    }

    // Load terrain cfg file.
    set_config_file(cfgfname.c_str());
    myid = get_config_int(NULL, "id", 0);

    // Load terrain image.
    PALETTE pal;
    BITMAP_PTR fileimage(load_bitmap(imagefname.c_str(), pal), bitmap_deleter);
    for (int i = 0; i != myimages.size(); ++i) {
        BITMAP_PTR ptr(create_bitmap(24, 24), bitmap_deleter);
        myimages[i] = ptr;
        blit(fileimage.get(), image(i), (i % 9)*25, (i / 9)*25, 0, 0, 24, 24);
    }
}
