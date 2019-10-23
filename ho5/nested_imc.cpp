#include <iostream>
#include <fstream>
#include <IMC/Spec/PlanSpecification.hpp>
#include <IMC/Spec/SetEntityParameters.hpp>
#include <IMC/Spec/EntityParameter.hpp>
#include <IMC/Spec/Loiter.hpp>
#include <IMC/Base/ByteBuffer.hpp>
#include <IMC/Base/Packet.hpp>
#define LAUVXPLORE1 (30)
using namespace IMC;

int main()
{
	std::stringstream buf;

	EntityParameter ep;
	ep.name = "Active";
	ep.value = "false";

	SetEntityParameters sep;
	sep.name = "LBL";
	sep.params.push_back(ep);

	Loiter loiter;
	loiter.timeout = 10000;
	loiter.lat = 0.7188916469344056;
	loiter.lon = -0.15194250254286037;
	loiter.z = 3;
	loiter.z_units = 1;
	loiter.duration = 3000;
	loiter.speed = 1000;
	loiter.speed_units = 1;
	loiter.type = 1;
	loiter.radius = 20;
	loiter.length = 1;
	loiter.bearing = 0;
	loiter.direction = 1;
	loiter.custom = "";

	PlanManeuver planman;
	planman.maneuver_id = "1";
	planman.data.set(loiter);
	planman.start_actions.push_back(sep);
	planman.end_actions.clear();


	PlanSpecification planspec;
	planspec.setTimeStamp(1.5628304294681385E9);
	planspec.setSource(16652);
	planspec.setSourceEntity(44);
	planspec.setDestination(30);
	planspec.setDestinationEntity(255);
	planspec.plan_id = "cmd-lauv-xplore-1";
	planspec.description = "";
	planspec.vnamespace = "";
	planspec.variables.clear();
	planspec.start_man_id = "1";
	planspec.maneuvers.push_back(planman);

	planspec.toJSON(buf);

	std::ofstream file("nested_msg.json");
    file << buf.str() << std::endl;
    file.close();

	std::cout << buf.str();
}
