(ns lucka01.core-test
  (:require [clojure.test :refer :all]
            [lucka01.core :refer :all]))

(deftest test1-1
  (testing "Test 1-1"
    (is (= (add-numbers [1 1 1]) 3))))

(deftest test1-2
  (testing "Test 1-2"
    (is (= (add-numbers [1 1 -2]) 0))))

(deftest test1-3
  (testing "Test 1-3"
    (is (= (add-numbers [-1 -2 -3]) -6))))
