#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

std::vector<std::vector<int>> parseReports(const std::string& reportsFile)
{
	std::vector<std::vector<int>> reports;
	std::ifstream input(reportsFile);

	if (!input)
	{
		std::cerr << "Unable to open file\n";
	}

	std::string report;
	while (std::getline(input, report))
	{
		std::stringstream ss(report);
		std::vector<int> reportVector;
		int num;
		while (ss >> num)
			reportVector.push_back(num);
		reports.push_back(reportVector);
	}

	input.close();
	return reports;
}

bool isReportSafe(const std::vector<int>& report)
{
	bool ascending = report[1] > report[0];

	for (int i = 1; i < report.size(); i++)
	{
		if (ascending && (report[i] - report[i - 1]  < 1 || report[i] - report[i - 1] > 3))
			return false;
		if (!ascending && (report[i - 1] - report[i] < 1 || report[i - 1] - report[i] > 3))
			return false;  
	}

	return true;
}

int main()
{
	const std::string reportsFile = "input";
	std::vector<std::vector<int>> reports = parseReports(reportsFile);

	int safeReports = 0;
	for (const auto& report : reports) 
	{
		if (isReportSafe(report))
			safeReports++;
    }

	std::cout << "Safe Reports: " << safeReports << '\n';

	return 0;
}
