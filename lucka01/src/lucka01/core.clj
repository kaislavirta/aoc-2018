(ns lucka01.core)

(require '[clojure.edn :as edn])

(defn add-numbers
	[numbers]
	(reduce + numbers))

(defn -main
	[]
	(let [numbers (as-> (slurp "resources/input.txt") value
		(clojure.string/split-lines value)
			(into [] (map #(edn/read-string %) value)))]
		(println (add-numbers numbers))))
