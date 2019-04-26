(ns lucka25.core
  	(:gen-class))

(require '[clojure.edn :as edn])

(defn parse-point [line]
	(let [parts (.split line ",")]
      	(into [] (map #(edn/read-string %) parts))))

(defn abs [n] (max n (- n)))

(defn manhattan-distance [p1 p2]
	(reduce + (map abs (map - p1 p2))))

(defn fits-constellation [point constellation]
	(some #(<= (manhattan-distance point %) 3) constellation))

; input is a point [1 2 3 4] and constellations [[[2 3 4 5] [1 3 4 5]] [[8 9 10 11]]]
(defn add-constellation [constellations point]
	(remove nil? (let [groups (group-by #(fits-constellation point %) constellations)]
		(def yes (list (conj (into [] (reduce concat (get groups true))) point)))
		(def no (let [the-rest (get groups nil)]
			(if (some? the-rest) (apply concat (vector the-rest)) nil)))
		(concat yes no))))

(defn create-constellations [points]
	(reduce add-constellation nil points))

(defn -main
	[]
	(let [points (as-> (slurp "resources/input.txt") value
		(clojure.string/split-lines value)
          	(into [] (map parse-point value)))]
		(println (count (create-constellations points)))))
