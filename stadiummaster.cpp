#include "stadiummaster.h"

StadiumMaster::StadiumMaster(bool *selectStadiumIndex)
{
    this->selectStadiumIndex = selectStadiumIndex;

    stadiumCount = 30;

    const QString names[30] = {
        "American Family Field",
        "Angel Stadium",
        "Busch Stadium",
        "Chase Field",
        "Citi Field",
        "Citizens Bank Park",
        "Comerica Park",
        "Coors Field",
        "Dodger Stadium",
        "Fenway Park",
        "Globe Life Field",
        "Great American Ball Park",
        "Guaranteed Rate Field",
        "Kauffman Stadium",
        "loanDepot park",
        "Minute Maid Park",
        "Nationals Park",
        "Oracle Park",
        "Oriole Park at Camden Yards",
        "Petco Park",
        "PNC Park",
        "Progressive Field",
        "RingCentral Coliseum",
        "Rogers Centre",
        "T-Mobile Park",
        "Target Field",
        "Tropicana Field",
        "Truist Park",
        "Wrigley Field",
        "Yankee Stadium"
    };
    const int capacity[30] = {
        41900, 45517, 45494, 48405, 41922,
        42792, 41083, 50144, 56000, 37555,
        40300, 42319, 40615, 37903, 36742,
        41168, 41339, 41265, 45971, 40209,
        38747, 34830, 46847, 49286, 47929,
        38544, 25000, 41084, 41649, 46537
    };
    const QString locations[30] = {
        "Milwaukee, Wisconsin",
        "Anaheim, California",
        "St. Louis, Missouri",
        "Phoenix, Arizona",
        "Queens, New York",
        "Philadelphia, Pennsylvania",
        "Detroit, Michigan",
        "Denver, Colorado",
        "Los Angeles, California",
        "Boston, Massachusetts",
        "Arlington, Texas",
        "Cincinnati, Ohio",
        "Chicago, Illinois",
        "Kansas City, Missouri",
        "Miami, Florida",
        "Houston, Texas",
        "Washington, D.C.",
        "San Francisco, California",
        "Baltimore, Maryland",
        "San Diego, California",
        "Pittsburgh, Pennsylvania",
        "Cleveland, Ohio",
        "Oakland, California",
        "Toronto, Ontario",
        "Seattle, Washington",
        "Minneapolis, Minnesota",
        "St. Petersburg, Florida",
        "Cumberland, Georgia",
        "Chicago, Illinois",
        "Bronx, New York"
    };

    const bool hasGrass[30] = {
        true, true, true, false, true,
        true, true, true, true, true,
        false, true, true, true, false,
        true, true, true, true, true,
        true, true, true, false, true,
        true, false, true, true, true,
    };

    const QString teams[30] = {
        "Milwaukee Brewers",
        "Los Angeles Angels",
        "St. Louis Cardinals",
        "Arizona Diamondbacks",
        "New York Mets",
        "Philadelphia Phillies",
        "Detroit Tigers",
        "Colorado Rockies",
        "Los Angeles Dodgers",
        "Boston Red Sox",
        "Texas Rangers",
        "Cincinnati Reds",
        "Chicago White Sox",
        "Kansas City Royals",
        "Miami Marlins",
        "Houston Astros",
        "Washington Nationals",
        "San Francisco Giants",
        "Baltimore Orioles",
        "San Diego Padres",
        "Pittsburgh Pirates",
        "Cleveland Guardians",
        "Oakland Athletics",
        "Toronto Blue Jays",
        "Seattle Mariners",
        "Minnesota Twins",
        "Tampa Bay Rays",
        "Atlanta Braves",
        "Chicago Cubs",
        "New York Yankees",
    };

    const int opened[30] = {
        2001, 1966, 2006, 1998, 2009,
        2004, 2000, 1995, 1962, 1912,
        2020, 2003, 1991, 1973, 2012,
        2000, 2008, 2000, 1992, 2004,
        2001, 1994, 1966, 1989, 1999,
        2010, 1990, 2017, 1914, 2009
    };

    const bool isAmerican[30] = {
        true, true, false, true, false,
        false, false, true, false, true,
        true, true, false, false, true,
        true, false, true, false, false,
        true, true, false, false, false,
        false, true, true, false, false,
    };

    stadiums = new Stadium*[100];


    for(int i = 0; i < stadiumCount; i ++)
    {
        stadiums[i] = new Stadium(names[i], capacity[i], locations[i], isAmerican[i], hasGrass[i], teams[i], opened[i]);
        stadiumGraph.addVertex(names[i].toStdString());
    }

    const int edgesList[54][3] = {
        { 24, 17, 680 },
        { 17, 1, 340 },
        { 1, 19, 110 },
        { 19, 3, 300 },
        { 17, 3, 650 },
        { 3, 7, 580 },
        { 19, 7, 830 },
        { 1, 25, 1500 },
        { 3, 10, 870 },
        { 3, 15, 1115 },
        { 10, 15, 230 },
        { 7, 10, 650 },
        { 10, 13, 460 },
        { 7, 13, 560 },
        { 7, 10, 650 },
        { 24, 25, 1390 },
        { 15, 2, 680 },
        { 13, 2, 235 },
        { 25, 2, 465 },
        { 25, 0, 300 },
        { 0, 12, 80 },
        { 13, 12, 415 },
        { 2, 11, 310 },
        { 12, 11, 250 },
        { 10, 27, 740 },
        { 15, 26, 790 },
        { 15, 14, 965 },
        { 24, 23, 2070 },
        { 0, 23, 430 },
        { 12, 6, 240 },
        { 6, 21, 90 },
        { 11, 21, 225 },
        { 11, 27, 375 },
        { 26, 14, 210 },
        { 27, 14, 600 },
        { 11, 26, 790 },
        { 27, 16, 560 },
        { 16, 14, 930 },
        { 6, 23, 210 },
        { 21, 20, 115 },
        { 11, 20, 260 },
        { 23, 20, 225 },
        { 23, 9, 430 },
        { 20, 4, 315 },
        { 20, 16, 195 },
        { 16, 5, 90 },
        { 5, 4, 80 },
        { 4, 9, 195 },
        { 14, 9, 1255 },
        { 8, 1, 1 },
        { 17, 22, 1 },
        { 12, 28, 1 },
        { 16, 18, 1 },
        { 4, 29, 1 }
    };

    for(int i = 0; i < 54; i++)
    {
        stadiumGraph.addUndirectedEdge(edgesList[i][0], edgesList[i][1], edgesList[i][2]);
    }

//    qDebug() << QString::fromStdString(stadiumGraph.printGraph());
}
