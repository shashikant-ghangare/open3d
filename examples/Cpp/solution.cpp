#include <iostream>
#include "Open3D/Open3D.h"
#include <fstream>



void PrintHelp() {
    using namespace open3d;
    utility::LogInfo("Usage :");
    utility::LogInfo("    >  <path_to_mesh_file>");
}
int main(int argc, char *argv[])
{
using namespace open3d;
	utility::SetVerbosityLevel(utility::VerbosityLevel::Debug);

    if (argc < 2) {
    PrintHelp();
    return 1;
    }

	auto mesh = io::CreateMeshFromFile(argv[1]);

	utility::LogInfo("Mesh has {:d} vertices, {:d} triangles.",
                         mesh->vertices_.size(), mesh->triangles_.size());

    auto connected_components = mesh->IdenticallyColoredConnectedComponents();

    std::ofstream res_file ("results.txt");


    if(res_file.is_open()){
        for (int i = 0; i < int(connected_components.size()); i++ )
            for(int j = 0; j<int(connected_components[i].size()); j++){
                for(auto k: connected_components[i][j]){
                    res_file<<k<<' ';
                }
                res_file<<"\n";
            }
        res_file.close();
    }
    else std::cout << "Unable to open file";

    return 0;
}
