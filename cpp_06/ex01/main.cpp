/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicolau <tnicolau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 09:53:02 by tnicolau          #+#    #+#             */
/*   Updated: 2024/08/20 09:53:04 by tnicolau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int	main()
{
	Data	data;
	data.num = 42;
	data.str = "Basic string";

	uintptr_t	serializer = Serializer::serialize(&data);
	Data	*deserializedData = Serializer::deserialize(serializer);

	std::cout << "Original data :" << std::endl;
	std::cout << data.num << std::endl;
	std::cout << data.str << std::endl;

	std::cout << "Serialized data :" << std::endl;
	std::cout << deserializedData->num << std::endl;
	std::cout << deserializedData->str << std::endl;

	if (data.num != deserializedData->num || data.str != deserializedData->str)
		std::cout << "Values are not equal after deserialization, program failed" << std::endl;
	else
		std::cout << "Values are equal after deserialization, program succeeded" << std::endl;
	return 0;
}
