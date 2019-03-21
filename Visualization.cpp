#include <pcl/visualization/pcl_visualizer.h>
#include <pcl/point_types.h>

int START_FRAME = 2;
const int END_FRAME = 18815;
const int BACKGROUND = 1;

int main()
{
    //vis statements
    pcl::visualization::PCLVisualizer vis("3D View");
    //vis.addCoordinateSystem(100);
    //read background
    std::string source = "../17_02_2019_14_46_01/M8-192.168.1.9/frame-";
    std::string file_type = ".txt";
    std::string file = source + std::to_string(BACKGROUND) + file_type;
    std::ifstream infile(file);
    
    //pcl statements
    pcl::PointCloud<pcl::PointXYZ>::Ptr Background (new pcl::PointCloud<pcl::PointXYZ>);
    // visualization statements
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> blue(Background,0,0,255);
    // read file
    for(std::string line; std::getline(infile, line);)
    {
        // create structure
        pcl::PointXYZ Points;
        std::string timestamp;
        std::istringstream in (line);
        in >> Points.x >> Points.y >> Points.z >> timestamp;
        Background->push_back(Points);
    }
    while(!vis.wasStopped())
    {
    vis.removeAllPointClouds();
    /*std::string source = "../data_new2/frame-";
    std::string file_type = ".txt";
    std::string file = source + std::to_string(BACKGROUND) + file_type;
    std::ifstream infile(file);
    
    //pcl statements
    pcl::PointCloud<pcl::PointXYZ>::Ptr Background (new pcl::PointCloud<pcl::PointXYZ>);
    // visualization statements
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> blue(Background,0,0,255);
    // read file
    for(std::string line; std::getline(infile, line);)
    {
        // create structure
        pcl::PointXYZ Points;
        std::istringstream in (line);
        in >> Points.x >> Points.y >> Points.z;
        Background->push_back(Points);
    }*/
    //vis.addPointCloud(Background,blue,"Background",0);
    
    // read DATA
    // pcl statements
    pcl::PointCloud<pcl::PointXYZ>::Ptr Data (new pcl::PointCloud<pcl::PointXYZ>);
    // visualization statements
    pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> red(Data,255,0,0);
    //read file
    //for(START_FRAME ; START_FRAME < END_FRAME+1 ; START_FRAME++)
    {
        std::string source = "../17_02_2019_14_46_01/M8-192.168.1.9/frame-";
        std::string file_type = ".txt";
        std::string file = source + std::to_string(START_FRAME) + file_type;
        std::ifstream infile(file);
        // pcl statements
        //pcl::PointCloud<pcl::PointXYZ>::Ptr Data (new pcl::PointCloud<pcl::PointXYZ>);
        // visualization statements
        //pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green(Data,0,255,0);
        // read file
        for(std::string line; std::getline(infile, line);)
        {
            // create structure
            pcl::PointXYZ Points;
            std::string timestamp;
            std::istringstream in (line);
            in >> Points.x >> Points.y >> Points.z >> timestamp;
            Data->push_back(Points);
        }
        //Visualization
        //vis.addPointCloud(Data,green,"Data",0);
    }
    //Visualization
    //vis.addPointCloud(Data,green,"Data",0);
    // visualization
    vis.addPointCloud(Background,blue,"Background",0);
    vis.addPointCloud(Data,red,"Data",0);
    vis.setPointCloudRenderingProperties(pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 1, "Data");
    
    //OpenWindow
    //while(!vis.wasStopped())
    //{
        // read file
        /*for(START_FRAME ; START_FRAME < END_FRAME+1 ; START_FRAME++)
        {
            std::string source = "../data/frame-";
            std::string file_type = ".txt";
            std::string file = source + std::to_string(START_FRAME) + file_type;
            std::ifstream infile(file);
            // pcl statements
            pcl::PointCloud<pcl::PointXYZ>::Ptr Data (new pcl::PointCloud<pcl::PointXYZ>);
            // visualization statements
            pcl::visualization::PointCloudColorHandlerCustom<pcl::PointXYZ> green(Data,0,255,0);
            // read file
            for(std::string line; std::getline(infile, line);)
            {
                // create structure
                pcl::PointXYZ Points;
                std::istringstream in (line);
                in >> Points.x >> Points.y >> Points.z;
                Data->push_back(Points);
            }
            //Visualization
            vis.addPointCloud(Data,green,"Data",0);
        }*/
        // vis start and enable spin
        vis.spinOnce();
        START_FRAME++;
    //}
    }
    return 0;
}
