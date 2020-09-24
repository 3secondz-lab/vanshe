
(cl:in-package :asdf)

(defsystem "gins-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ins" :depends-on ("_package_ins"))
    (:file "_package_ins" :depends-on ("_package"))
  ))