/**
 * @file KDTree.h
 * @brief K-Dimensional Tree implementation for efficient nearest neighbor search
 *
 * Implements a 2D K-D Tree for fast spatial queries, specifically nearest neighbor search.
 * The tree recursively partitions space by alternating between x and y coordinates.
 *
 * Features:
 * - Efficient nearest neighbor search
 * - Logarithmic average case performance
 * - Space partitioning optimization
 *
 * Time complexity: O(log n) average for nearest neighbor search
 * Space complexity: O(n)
 */

// filepath: e:\Playground\KDTree.h
#pragma once
#include <vector>
#include <algorithm>
#include <math.h>
#include <limits>

/**
 * @struct Point
 * @brief Represents a 2D point with integer coordinates
 */
struct Point {
	int x, y;  ///< X and Y coordinates of the point
};

/**
 * @class KDTree
 * @brief 2D K-Dimensional Tree for spatial data structure operations
 *
 * Organizes 2D points in a binary tree where each level alternates
 * the splitting dimension (x or y coordinate).
 */
class KDTree{    /**
	 * @struct Node
	 * @brief Internal node structure for the K-D Tree
	 */
	struct Node {
		Point p;                    ///< Point stored at this node
		Node* right, *left;         ///< Pointers to left and right children
	};
public:
	/**
	 * @brief Constructor that builds the K-D Tree from a vector of points
	 * @param points Vector of 2D points to organize in the tree
	 *
	 * Recursively builds a balanced tree by sorting points along alternating dimensions.
	 */
	KDTree(std::vector<Point>& points) {
		root = build(points, 0);
	}

	/**
	 * @brief Finds the nearest point to a given query point
	 * @param queryPoint The point to find the nearest neighbor for
	 * @return The closest point in the tree to the query point
	 *
	 * Uses the K-D Tree structure to efficiently prune search space
	 * and find the nearest neighbor.
	 * Time complexity: O(log n) average case, O(n) worst case
	 */
	Point findNearestPoint(Point queryPoint){
		Point bestPoint = {};
		double bestDistance = 0.0;
		nearest(root, queryPoint, 0, bestPoint, bestDistance);
		return bestPoint;
	}

private:
	double distance(const Point& a, const Point& b) {
		return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
	}

	Node* build(const std::vector<Point>& points, int depth = 0) {
		if (points.empty()) return nullptr;
		int axis = depth % 2 == 0; // 0 for x and 1 for y

		std::sort(points.begin(), points.end(), [&](const auto& a, const auto& b){
			return (axis == 0) ? a.x < b.x : a.y < b.y;
		});

		int mid = points.size() / 2;

		Node* rootNode = new Node();
		rootNode->p = points[mid];

		std::vector<Point> leftVector(points.begin(), points.begin() + mid);
		std::vector<Point> rightVector(points.begin() + mid + 1, points.end());

		rootNode->left  = build(leftVector, depth + 1);
		rootNode->right = build(rightVector, depth + 1);

		return rootNode;
	}

	void nearest(Node* root, Point queryPoint, int depth, Point& bestPoint, double bestDistance) {
		if (!root) return;

		auto d = distance(queryPoint, root->p);
		if (d < bestDistance) {
			bestDistance = d;
			bestPoint = root->p;
		}

		int axis = depth % 2; // 0 for x and 1 for y;

		Node* goNear = 0;
		Node* goFar = 0;

		if (((axis == 0) && queryPoint.x < root->p.x) || (axis == 1) && queryPoint.y < root->p.y) {
			goNear = root->left;
			goFar = root->right;
		} else {
			goNear = root->right;
			goFar = root->left;
		}

		nearest(goNear, queryPoint, depth + 1, bestPoint, bestDistance);

		double planeDistance = axis == 0 ? std::abs(queryPoint.x - root->p.x) : std::abs(queryPoint.y - root->p.y);

		if (planeDistance < bestDistance) {
			nearest(goFar, queryPoint, depth + 1, bestPoint, bestDistance);
		}
	}

private:
	Node* root;
};
