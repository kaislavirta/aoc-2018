(ns lucka25.core-test
  (:require [clojure.test :refer :all]
            [lucka25.core :refer :all]))

(deftest test-1
  (testing "Test 1"
  	(def test-data [
		[0 0 0 0] [3 0 0 0] [0 3 0 0]
		[0 3 0 0] [0 0 3 0] [0 0 0 3]
		[0 0 0 6] [9 0 0 0] [12 0 0 0]])
	(is (= (count (create-constellations test-data)) 2))))

(deftest test-2
  (testing "Test 2"
  	(def test-data [
		[-1 2 2 0] [0 0 2 -2] [0 0 0 -2]
		[-1 2 0 0] [-2 -2 -2 -2] [3 0 2 -1]
		[-1 3 2 2] [-1 0 -1 0] [0 2 1 -2]
		[3 0 0 0]])
	(is (= (count (create-constellations test-data)) 4))))

(deftest test-3
  (testing "Test 3"
  	(def test-data [
		[1 -1 0 1] [2 0 -1 0] [3 2 -1 0]
		[0 0 3 1] [0 0 -1 -1] [2 3 -2 0]
		[-2 2 0 0] [2 -2 0 -1] [1 -1 0 -1]
		[3 2 0 2]])
	(is (= (count (create-constellations test-data)) 3))))

(deftest test-4
  (testing "Test 4"
  	(def test-data [
		[1 -1 -1 -2] [-2 -2 0 1] [0 2 1 3]
		[-2 3 -2 1] [0 2 3 -2] [-1 -1 1 -2]
		[0 -2 -1 0] [-2 2 3 -1] [1 2 2 0]
		[-1 -2 0 -2]])
	(is (= (count (create-constellations test-data)) 8))))
