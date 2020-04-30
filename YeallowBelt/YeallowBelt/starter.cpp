#include <string>
#include <iostream>
#include <cassert>
#include <vector>
#include <map>

using namespace std;

enum class QueryType {
  NewBus,
  BusesForStop,
  StopsForBus,
  AllBuses
};

struct Query {
  QueryType type;
  string bus;
  string stop;
  vector<string> stops;
};

istream& operator >> (istream& is, Query& q) {
	string command;
	is >> command;

	if (command == "NEW_BUS")
	{
		int stopsCount;
		vector <string> stopNames;
		q.type = QueryType::NewBus;
		is >> q.bus;
		is >> stopsCount;
		for (int i = 0; i < stopsCount; i++)
		{
			string stopName;
			is >> stopName;
			stopNames.push_back(stopName);
		}
		q.stops = stopNames;
	}
	else if (command == "BUSES_FOR_STOP")
	{
		q.type = QueryType::BusesForStop;
		is >> q.stop;
	}
	else if (command == "STOPS_FOR_BUS")
	{
		q.type = QueryType::StopsForBus;
		is >> q.bus;
	}
	else if (command == "ALL_BUSES")
	{
		q.type = QueryType::AllBuses;
	}
  return is;
}

struct BusesForStopResponse {
	string stop;
	vector<string> stopsForBuses;
};

ostream& operator << (ostream& os, const BusesForStopResponse& r) {
	if (r.stopsForBuses.empty()) {
		os << "No stop";
	}
	else {
		for (const string& bus : r.stopsForBuses) {
			os << bus << " ";
		}
	}
  return os;
}

struct StopsForBusResponse {
	string bus;
	map<string, vector<string>> busesToStop;
	map<string, vector<string>> stopsToBuses;
};

ostream& operator << (ostream& os, const StopsForBusResponse& r) {
	if (r.busesToStop.count(r.bus) == 0) {
		os << "No bus";
	}
	else {
		for (const string& stop : r.busesToStop.at(r.bus)) {
			os << "Stop " << stop << ": ";
			if (r.stopsToBuses.at(stop).size() == 1) {
				os << "no interchange";
			}
			else {
				for (const string& other_bus : r.stopsToBuses.at(stop)) {
					if (r.bus != other_bus) {
						os << other_bus << " ";
					}
				}
			}
			os << endl;
		}
	}
  return os;
}

struct AllBusesResponse {
	map<string, vector<string> > buses;
};

ostream& operator << (ostream& os, const AllBusesResponse& r) {
	if (r.buses.empty()) {
		os << "No buses";
	}
	else {
		for (const auto& bus_item : r.buses) {
			os << "Bus " << bus_item.first << ": ";
			for (const string& stop : bus_item.second) {
				os << stop << " ";
			}
			os << endl;
		}
	}
  return os;
}

class BusManager {
public:
  void AddBus(const string& bus, const vector<string>& stops) {
   
	  buses_to_stops[bus] = stops;
	  for (auto stop : stops)
	  {
		  stops_to_buses[stop].push_back(bus);
	  }
  }

  BusesForStopResponse GetBusesForStop(const string& stop) const {
	  BusesForStopResponse ret;
	  ret.stop = stop;
	  
	  if (stops_to_buses.count(stop))
	  {
		  ret.stopsForBuses = stops_to_buses.at(stop);
	  }
	  else
	  {
		  ret.stopsForBuses = vector<string>();
	  }
	  return ret;
  }

  StopsForBusResponse GetStopsForBus(const string& bus) const {
	  StopsForBusResponse ret;
	  ret.bus = bus;
	  ret.busesToStop = buses_to_stops;

	  if (buses_to_stops.count(bus))
	  {		  
		  for (auto stop : buses_to_stops.at(bus))
		  {
			  ret.stopsToBuses[stop] = stops_to_buses.at(stop);
		  }
	  }
	  
	  return ret;
  }

  AllBusesResponse GetAllBuses() const {
	  AllBusesResponse resp;
	  resp.buses = buses_to_stops;
	  return resp;
  }
private:
	map<string, vector<string>> buses_to_stops, stops_to_buses;
};

int main() {
  int query_count;
  Query q;

  cin >> query_count;

  BusManager bm;
  for (int i = 0; i < query_count; ++i) {
    cin >> q;
    switch (q.type) {
    case QueryType::NewBus:
      bm.AddBus(q.bus, q.stops);
      break;
    case QueryType::BusesForStop:
      cout << bm.GetBusesForStop(q.stop) << endl;
      break;
    case QueryType::StopsForBus:
      cout << bm.GetStopsForBus(q.bus) << endl;
      break;
    case QueryType::AllBuses:
      cout << bm.GetAllBuses() << endl;
      break;
    }
  }

  return 0;
}