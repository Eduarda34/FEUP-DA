#include <iostream>
#include "../.h/Data.h"
#include "../.h/reservoirs.h"
#include "../.h/stations.h"
#include "../.h/pipes.h"
#include "../.h/cities.h"
#include "../.h/graph.h"

int main() {
    Data data1;
    graph* g1 = new graph();
    unsigned short answer;

    do {
        cout <<
             "1.Maximum Flow                       " << endl <<
             "2.Water Demand vs. Actual Flow       " << endl <<
             "3.Remove A Reservoir                 " << endl <<
             "4.Remove A Station                   " << endl <<
             "5.Remove A Pipe                      " << endl <<
             "6.Quit                               " << endl;
        cin >> answer;
        if(cin.eof()){
            exit(0);
        }
        if(!cin.good()) {
            cout << "Not An Option. Choose Another One." << endl;
            cin.clear();
            cin.ignore(numeric_limits<int>::max(), '\n');
            continue;
        }
        switch (answer) {

            case 1: {
                int line = 0;
                for(auto v : data1.getCities()) {
                    cout << v.getCity() << " " << v.getCode() << " " << endl;
                    line++;
                }
                string choice;
                cout << "Choose a specific City or type ALL to get every Max Flow:" << endl;
                cin >> choice;

                if(choice == "ALL") {
                    for(auto v : data1.getCities()) {
                        double maxFlow = g1->vertexMaxFlow(g1,v.getCode());
                        cout << "The City of " << v.getCity() << " gets " << maxFlow << " max flow" << endl;
                    }
                } else {
                    for(auto v : data1.getCities()) {
                        if(choice == v.getCity()) {
                            double maxFlow = g1->vertexMaxFlow(g1,v.getCode());
                            cout << "The City of " << choice << " gets " << maxFlow << " max flow" << endl;
                        }
                    }
                }
            }

            case 2: {
                g1->metricsAnalysis(g1);
            }

            case 3: {
                string code;
                int line = 0;
                for(auto v : data1.getReservoirs()) {
                    cout << v.getName() << " " << v.getCode() << " " << endl;
                    line++;
                }
                cout << "Type a reservoirs code to be removed: " << endl;
                cin >> code;
                g1->vertexRemovalFailures(g1,code);
            }

            case 4: {
                string code;
                int line = 0;
                for(auto v : data1.getStations()) {
                    cout << v.getId() << " " << v.getCode() << " " << endl;
                    line++;
                }
                cout << "Type a stations code to be removed: " << endl;
                cin >> code;
                g1->vertexRemovalFailures(g1,code);
            }

            case 5: {
                vector<pair<std::string, std::string>> pipes;
                string choice;
                string source;
                string dest;

                int line = 0;
                for(auto v : data1.getPipes()) {
                    cout << v.getSpA() << " " << v.getSpB() << " " << endl;
                    line++;
                }

                do {
                    cout << "Enter a valid source node: ";
                    cin >> source;
                    cout << "Enter the respective dest node: ";
                    cin >> dest;

                    pipes.emplace_back(source,dest);

                    cout << "Do you want to remove more pipes? (y/n): ";
                    cin >> choice;
                } while (choice == "y" || choice == "Y");

                g1->pipelineRemovalFailures(g1,pipes);
            }

            case 6: {
                exit(0);
            }
            default: {
                cout << "Not An Option. Choose Another One." << endl;
            }
        }
    } while(true);

    return 0;
}
