;; Auto-generated. Do not edit!


(when (boundp 'client::Position)
  (if (not (find-package "CLIENT"))
    (make-package "CLIENT"))
  (shadow 'Position (find-package "CLIENT")))
(unless (find-package "CLIENT::POSITION")
  (make-package "CLIENT::POSITION"))
(unless (find-package "CLIENT::POSITIONREQUEST")
  (make-package "CLIENT::POSITIONREQUEST"))
(unless (find-package "CLIENT::POSITIONRESPONSE")
  (make-package "CLIENT::POSITIONRESPONSE"))

(in-package "ROS")





(defclass client::PositionRequest
  :super ros::object
  :slots (_X ))

(defmethod client::PositionRequest
  (:init
   (&key
    ((:X __X) 0)
    )
   (send-super :init)
   (setq _X (round __X))
   self)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:serialization-length
   ()
   (+
    ;; int64 _X
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _X) (= (length (_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_X . bv) 0) 0) s)
              (write-long (ash (elt (_X . bv) 1) -1) s))
             ((and (class _X) (= (length (_X . bv)) 1)) ;; big1
              (write-long (elt (_X . bv) 0) s)
              (write-long (if (>= _X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _X s)(write-long (if (>= _X 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _X
#+(or :alpha :irix6 :x86_64)
      (setf _X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass client::PositionResponse
  :super ros::object
  :slots (_X ))

(defmethod client::PositionResponse
  (:init
   (&key
    ((:X __X) 0)
    )
   (send-super :init)
   (setq _X (round __X))
   self)
  (:X
   (&optional __X)
   (if __X (setq _X __X)) _X)
  (:serialization-length
   ()
   (+
    ;; int64 _X
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _X
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _X (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _X) (= (length (_X . bv)) 2)) ;; bignum
              (write-long (ash (elt (_X . bv) 0) 0) s)
              (write-long (ash (elt (_X . bv) 1) -1) s))
             ((and (class _X) (= (length (_X . bv)) 1)) ;; big1
              (write-long (elt (_X . bv) 0) s)
              (write-long (if (>= _X 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _X s)(write-long (if (>= _X 0) 0 #xffffffff) s)))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _X
#+(or :alpha :irix6 :x86_64)
      (setf _X (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _X (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;;
   self)
  )

(defclass client::Position
  :super ros::object
  :slots ())

(setf (get client::Position :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get client::Position :datatype-) "client/Position")
(setf (get client::Position :request) client::PositionRequest)
(setf (get client::Position :response) client::PositionResponse)

(defmethod client::PositionRequest
  (:response () (instance client::PositionResponse :init)))

(setf (get client::PositionRequest :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get client::PositionRequest :datatype-) "client/PositionRequest")
(setf (get client::PositionRequest :definition-)
      "int64 X
---
int64 X


")

(setf (get client::PositionResponse :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get client::PositionResponse :datatype-) "client/PositionResponse")
(setf (get client::PositionResponse :definition-)
      "int64 X
---
int64 X


")



(provide :client/Position "36c8dcf1c5586f27520f2080e30f4ae0")


