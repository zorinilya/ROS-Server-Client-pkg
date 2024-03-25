;; Auto-generated. Do not edit!


(when (boundp 'server::Position)
  (if (not (find-package "SERVER"))
    (make-package "SERVER"))
  (shadow 'Position (find-package "SERVER")))
(unless (find-package "SERVER::POSITION")
  (make-package "SERVER::POSITION"))
(unless (find-package "SERVER::POSITIONREQUEST")
  (make-package "SERVER::POSITIONREQUEST"))
(unless (find-package "SERVER::POSITIONRESPONSE")
  (make-package "SERVER::POSITIONRESPONSE"))

(in-package "ROS")





(defclass server::PositionRequest
  :super ros::object
  :slots (_X ))

(defmethod server::PositionRequest
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

(defclass server::PositionResponse
  :super ros::object
  :slots (_X ))

(defmethod server::PositionResponse
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

(defclass server::Position
  :super ros::object
  :slots ())

(setf (get server::Position :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get server::Position :datatype-) "server/Position")
(setf (get server::Position :request) server::PositionRequest)
(setf (get server::Position :response) server::PositionResponse)

(defmethod server::PositionRequest
  (:response () (instance server::PositionResponse :init)))

(setf (get server::PositionRequest :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get server::PositionRequest :datatype-) "server/PositionRequest")
(setf (get server::PositionRequest :definition-)
      "int64 X
---
int64 X


")

(setf (get server::PositionResponse :md5sum-) "36c8dcf1c5586f27520f2080e30f4ae0")
(setf (get server::PositionResponse :datatype-) "server/PositionResponse")
(setf (get server::PositionResponse :definition-)
      "int64 X
---
int64 X


")



(provide :server/Position "36c8dcf1c5586f27520f2080e30f4ae0")


