#include "Tokenizer.h"
/*
	Copyright (C) 2022  Barth.Feudong
	Author can be contacted here: <https://github.com/mrSchaffman/Cpp-Calculator>

	This file is part of the Calculator project.
	using the COM, the win32 API for the GUI,
	the MVC Architecture.

	Calculator is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	Calculator is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <https://www.gnu.org/licenses/>.

*/
#include<sstream>
#include<iterator>
#include<algorithm>

using std::string;
using std::istream;
using std::istream_iterator;

namespace utility
{
	Tokenizer::Tokenizer(const string & s)
	{
		std::istringstream iss{ s };
		tokenize(iss);
	}

	Tokenizer::Tokenizer(istream & s)
	{
		tokenize(s);
	}

	Tokenizer::~Tokenizer()
	{
	}

	void Tokenizer::tokenize(istream &s)
	{
		m_tokens.assign(istream_iterator<string>{s}, istream_iterator<string>{});

		// for each char in the token , to lower
		for (auto& token : m_tokens)
			std::transform(token.begin(), token.end(), token.begin(), ::tolower);
	}

}
