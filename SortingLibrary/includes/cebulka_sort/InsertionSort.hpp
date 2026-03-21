#ifndef INSERTION_SORT_HPP
#define INSERTION_SORT_HPP

#include "library_details/Predicators.hpp"
#include <iterator>

namespace ceb
{
	template<typename Container_it, typename Condition = ceb::details::increasingly_t>
	void insertion_sort(Container_it begin_it, Container_it end_it, Condition condition = {})
	{
		if (not ceb::details::is_sortable(begin_it, end_it))
			return;

		Container_it curr_it = std::next(begin_it);

		while (curr_it != end_it)
		{
			auto curr_value = std::move(*curr_it);
			Container_it temp_it = begin_it;

			while (not condition(curr_value, *temp_it) && temp_it != curr_it)
				++temp_it;

			while (temp_it != curr_it)
			{
				auto temp_value = std::move(*temp_it);
				*temp_it = std::move(curr_value);
				curr_value = std::move(temp_value);

				++temp_it;
			}

			*curr_it = std::move(curr_value);
			++curr_it;
		}
	}
}


#endif