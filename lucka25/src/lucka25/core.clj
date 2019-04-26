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
		(conj (vector (conj (into [] (reduce concat (get groups true))) point))
			(into [] (mapcat identity (get groups nil)))))))

(defn -main
	[]
	(let [points (as-> (slurp "resources/input.txt") value
		(clojure.string/split-lines value)
          	(into [] (map parse-point value)))]
		;(print points)))
  		(print (count (reduce add-constellation nil points)))))
