#include "rapidcsv.h"
#include <vector>
#include <cmath>
#include <cstdlib>
#include <Eigen/Dense>
#include <vector>
#include <iostream>
#include <random>

int male1 = 0, male2 = 0, male3 = 0, male4 = 0, male5 = 0;
int female1 = 0, female2 = 0, female3 = 0, female4 = 0, female5 = 0;
int ageH1 = 0, ageH2 = 0, ageH3 = 0, ageH4 = 0, ageH5 = 0; //High Age
int ageL1 = 0, ageL2 = 0, ageL3 = 0, ageL4 = 0, ageL5 = 0; //Low Age
int incomeH1 = 0, incomeH2 = 0, incomeH3 = 0, incomeH4 = 0, incomeH5 = 0; //High income
int incomeL1 = 0, incomeL2 = 0, incomeL3 = 0, incomeL4 = 0, incomeL5 = 0; //Low income
int rural1 = 0, rural2 = 0, rural3 = 0, rural4 = 0, rural5 = 0;
int urban1 = 0, urban2 = 0, urban3 = 0, urban4 = 0, urban5 = 0;
int nonRisk1 = 0, nonRisk2 = 0, nonRisk3 = 0, nonRisk4 = 0, nonRisk5 = 0;
int risk1 = 0, risk2 = 0, risk3 = 0, risk4 = 0, risk5 = 0;

int totalMale = 0, totalFemale = 0, totalAgeH = 0, totalAgeL = 0, totalIncomeH = 0, totalIncomeL = 0, totalRural = 0, totalUrban = 0, totalRisk = 0, totalnonRisk = 0;

void percentageResultsAndClusters(std::vector<std::vector<double>> data, std::vector<int> somNodes)
{
    std::cout << "Results:" << std::endl;

    for (int i = 0; i < somNodes.size(); i++)
    {
        std::cout << "\n" << somNodes[i];

        switch (somNodes[i])
        {
        case 0:
            if (data[i][40] == 0)
            {
            	nonRisk1++;
            }

            else
                risk1++;

            if (data[i][41] == 0)
                male1++;
            else
                female1++;

            if (data[i][42] == 0)
                ageL1++;
            else
                ageH1++;

            if (data[i][43] == 0)
                incomeL1++;
            else
                incomeH1++;

            if (data[i][44] == 0)
                rural1++;
            else
                urban1++;

        case 1:
            if (data[i][40] == 0)
                nonRisk2++;
            else
                risk2++;

            if (data[i][41] == 0)
                male2++;
            else
                female2++;

            if (data[i][42] == 0)
                ageL2++;
            else
                ageH2++;

            if (data[i][43] == 0)
                incomeL2++;
            else
                incomeH2++;

            if (data[i][44] == 0)
                rural2++;
            else
                urban2++;

        case 2:
            if (data[i][40] == 0)
                nonRisk3++;
            else
                risk3++;

            if (data[i][41] == 0)
                male3++;
            else
                female3++;

            if (data[i][42] == 0)
                ageL3++;
            else
                ageH3++;

            if (data[i][43] == 0)
                incomeL3++;
            else
                incomeH3++;

            if (data[i][44] == 0)
                rural3++;
            else
                urban3++;

        case 3:
            if (data[i][40] == 0)
                nonRisk4++;
            else
                risk4++;

            if (data[i][41] == 0)
                male4++;
            else
                female4++;

            if (data[i][42] == 0)
                ageL4++;
            else
                ageH4++;

            if (data[i][43] == 0)
                incomeL4++;
            else
                incomeH4++;

            if (data[i][44] == 0)
                rural4++;
            else
                urban4++;

        case 4:
            if (data[i][40] == 0)
                nonRisk5++;
            else
                risk5++;

            if (data[i][41] == 0)
                male5++;
            else
                female5++;

            if (data[i][42] == 0)
                ageL5++;
            else
                ageH5++;

            if (data[i][43] == 0)
                incomeL5++;
            else
                incomeH5++;

            if (data[i][44] == 0)
                rural5++;
            else
                urban5++;
        }

        if (data[i][40] == 0)
            totalnonRisk++;
        else
            totalRisk++;

        if (data[i][41] == 0)
            totalMale++;
        else
            totalFemale++;

        if (data[i][42] == 0)
            totalAgeL++;
        else
            totalAgeH++;

        if (data[i][43] == 0)
            totalIncomeL++;
        else
            totalIncomeH++;

        if (data[i][44] == 0)
            totalRural++;
        else
            totalUrban++;
    }

    std::cout << "Non-Risk in Cluster 1: " << nonRisk1 << "\n";
    std::cout << "Non-Risk in Cluster 2: " << nonRisk2 << "\n";
    std::cout << "Non-Risk in Cluster 3: " << nonRisk3 << "\n";
    std::cout << "Non-Risk in Cluster 4: " << nonRisk4 << "\n";
    std::cout << "Non-Risk in Cluster 5: " << nonRisk5 << "\n";
    std::cout << "Risk in Cluster 1: " << risk1 << "\n";
    std::cout << "Risk in Cluster 2: " << risk2 << "\n";
    std::cout << "Risk in Cluster 3: " << risk3 << "\n";
    std::cout << "Risk in Cluster 4: " << risk4 << "\n";
    std::cout << "Risk in Cluster 5: " << risk5 << "\n";
    std::cout << "Male in Cluster 1: " << male1 << "\n";
    std::cout << "Male in Cluster 2: " << male2 << "\n";
    std::cout << "Male in Cluster 3: " << male3 << "\n";
    std::cout << "Male in Cluster 4: " << male4 << "\n";
    std::cout << "Male in Cluster 5: " << male5 << "\n";
    std::cout << "Female in Cluster 1: " << female1 << "\n";
    std::cout << "Female in Cluster 2: " << female2 << "\n";
    std::cout << "Female in Cluster 3: " << female3 << "\n";
    std::cout << "Female in Cluster 4: " << female4 << "\n";
    std::cout << "Female in Cluster 5: " << female5 << "\n";
    std::cout << "Low Age in Cluster 1: " << ageL1 << "\n";
    std::cout << "Low Age in Cluster 2: " << ageL2 << "\n";
    std::cout << "Low Age in Cluster 3: " << ageL3 << "\n";
    std::cout << "Low Age in Cluster 4: " << ageL4 << "\n";
    std::cout << "Low Age in Cluster 5: " << ageL5 << "\n";
    std::cout << "High Age in Cluster 1: " << ageH1 << "\n";
    std::cout << "High Age in Cluster 2: " << ageH2 << "\n";
    std::cout << "High Age in Cluster 3: " << ageH3 << "\n";
    std::cout << "High Age in Cluster 4: " << ageH4 << "\n";
    std::cout << "High Age in Cluster 5: " << ageH5 << "\n";
    std::cout << "Low Income in Cluster 1: " << incomeL1 << "\n";
    std::cout << "Low Income in Cluster 2: " << incomeL2 << "\n";
    std::cout << "Low Income in Cluster 3: " << incomeL3 << "\n";
    std::cout << "Low Income in Cluster 4: " << incomeL4 << "\n";
    std::cout << "Low Income in Cluster 5: " << incomeL5 << "\n";
    std::cout << "High Income in Cluster 1: " << incomeH1 << "\n";
    std::cout << "High Income in Cluster 2: " << incomeH2 << "\n";
    std::cout << "High Income in Cluster 3: " << incomeH3 << "\n";
    std::cout << "High Income in Cluster 4: " << incomeH4 << "\n";
    std::cout << "High Income in Cluster 5: " << incomeH5 << "\n";
    std::cout << "Rural in Cluster 1: " << rural1 << "\n";
    std::cout << "Rural in Cluster 2: " << rural2 << "\n";
    std::cout << "Rural in Cluster 3: " << rural3 << "\n";
    std::cout << "Rural in Cluster 4: " << rural4 << "\n";
    std::cout << "Rural in Cluster 5: " << rural5 << "\n";
    std::cout << "Urban in Cluster 1: " << urban1 << "\n";
    std::cout << "Urban in Cluster 2: " << urban2 << "\n";
    std::cout << "Urban in Cluster 3: " << urban3 << "\n";
    std::cout << "Urban in Cluster 4: " << urban4 << "\n";
    std::cout << "Urban in Cluster 5: " << urban5 << "\n";

    std::cout << "Total Risk: " << totalRisk << "\n";
    std::cout << "Total Non-Risk: " << totalnonRisk << "\n";
    std::cout << "Total Male: " << totalMale << "\n";
    std::cout << "Total Female: " << totalFemale << "\n";
    std::cout << "Total Low Age: " << totalAgeL << "\n";
    std::cout << "Total High Age: " << totalAgeH << "\n";
    std::cout << "Total Low Income: " << totalIncomeL << "\n";
    std::cout << "Total High Income: " << totalIncomeH << "\n";
    std::cout << "Total Rural: " << totalRural << "\n";
    std::cout << "Total Urban: " << totalUrban << "\n";

}

int main()
{
    rapidcsv::Document doc("Data.csv");

	std::vector<std::vector<double>> internetData;

	for (int i = 0; i < 1220; i++) {
        internetData.push_back(doc.GetRow<double>(i));
    }

    std::vector<int> nodes = {0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,0,0,0,0,0,3,3,3,3,1,1,1,1,1,1,1,0,0,0,0,0,3,3,3,3,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,0,0,0,0,0,0,0,0,0,1,1,1,1,1,2,2,0,0,0,0,0,4,4,4,4,3,1,1,1,1,2,2,2,0,0,0,0,0,4,4,4,1,1,1,1,1,2,2,2,0,0,0,0,0,4,4,4,1,1,1,1,1,2,2,2,0,0,0,0,0,4,4,4,1,1,1,1,1,2,2,2,0,0,0,0};

    std::cout << nodes[0] << " THIS IS A NUMBER" << std::endl;
    percentageResultsAndClusters(internetData, nodes);
}