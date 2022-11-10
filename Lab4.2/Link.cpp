#include "Link.h"

namespace stefani_datastructure {

	Link* Link::insert(Link* previous_node, Link* node) {
		if (!previous_node) return node;
		if (!node) return previous_node;

		node->succ_ = previous_node;
		if(previous_node->prev_)
			previous_node->prev_->succ_ = node;
		 
		node->prev_ = previous_node->prev_;
		previous_node->prev_ = node;

		return node;
	}

	Link* Link::add(Link* next_node, Link* node)
	{
		if (!next_node) return node;
		if (!node) return next_node;

		node->prev_ = next_node;
		if (next_node->succ_)
			next_node->succ_->prev_ = node;

		node->succ_ = next_node->succ_;
		next_node->succ_ = node;

		return node;
	}

	Link* Link::erase(Link* node)
	{
		if (!node) return nullptr;

		if (node->prev_)
			node->prev_->succ_ = node->succ_;

		if(node->succ_)
			node->succ_->prev_ = node->prev_;

		return node->succ_; // Perchè ritorno il sucessivo?
	}

	Link* Link::find(Link* node, string& value)
	{
		while (node) {
			if (node->value_ == value)
				return node;

			node = node->succ_;
		}

		return nullptr;
	}

	Link* Link::advance(Link* node)
	{
		if (!node) return nullptr;
		return node->succ_;
	}

	

}