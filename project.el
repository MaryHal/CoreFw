(defvar rootDirShort "~/code/current/CoreFW/")
(defvar rootDir (expand-file-name rootDirShort))

(defun premake ()
  (interactive)
  (save-window-excursion
    (shell-command (concat "(cd " rootDir " && premake4 gmake && cd -)" )))
  )

(setq compile-command (concat "(cd " rootDir " && make -k -j && cd -)"))
(defun compile-quietly ()
  "Re-compile without changing the window configuration."
  (interactive)
  (save-window-excursion
    (recompile))
  )

(defun runProgram ()
  (interactive)
  (save-window-excursion
    (shell-command (concat "(cd " rootDir " && ./run && cd -)" )))
  )

(global-set-key (kbd "<f4>") 'premake)
(global-set-key (kbd "<f5>") 'compile)
;(global-set-key (kbd "<f5>") 'recompile-quietly)
(global-set-key (kbd "<f6>") 'runProgram)

(setq ac-clang-flags
      (append ac-clang-flags (split-string (concat "-I" rootDir "src")
                                           "/usr/include/GL")))

