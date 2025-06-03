Larger:
(defn larger [x, y] (if (> x y) x y))

Largest:
(defn larger [x, y] (if (> x y) x y))

isEven:
(defn larger [x, y] (if (> x y) x y))
 
evenAll:
(defn larger [x, y] (if (> x y) x y))

round:
(defn round [x] (Math/round x))

roundAll:
(defn roundAll [value] (map round value))

finalList:
(defn finalList [value] println[value] ((comp largest evenAll roundAll)vals))