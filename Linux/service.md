Below metioned is the kubelet.service file from /usr/lib/systemd/system/kubelet.service
```
[Unit]
Description=The Kubernetes Node Agent
Documentation=https://kubernetes.io/docs/reference/command-line-tools-reference/kubelet/
After=containerd.service crio.service docker.service

[Service]
ConfigurationDirectory=kubernetes
CPUAccounting=true
IPAccounting=true
EnvironmentFile=-/etc/kubernetes/kubelet.env
ExecStart=/usr/bin/kubelet $KUBELET_ARGS
KillMode=process
MemoryAccounting=true
StartLimitInterval=0
Restart=on-failure
RestartSec=10
RuntimeDirectory=kubelet
StateDirectory=kubelet

[Install]
WantedBy=multi-user.target
```


Here, the UNIT section contains metadata like Description and Documentation and also dependancy i.e after which services it should start
In the SERVICE section actual service is defined

Here from where to load the env file,
what binary to execute and pass which args

