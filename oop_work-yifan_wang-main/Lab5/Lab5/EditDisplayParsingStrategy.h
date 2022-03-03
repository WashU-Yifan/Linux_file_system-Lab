#pragma once
#include"../..//SharedCode/AbstractParsingStrategy.h"
#include<vector>
class EditDisplayParsingStrategy :public AbstractParsingStrategy {
public:
	virtual std::vector<std::string> parse(std::string input) override;

};